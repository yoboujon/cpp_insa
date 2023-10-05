# Module C++ INSA 4AE

## Compiler le projet

### Préparer la compilation

Pour compiler le projet je recommande CMake, mais il est possible d'utiliser directement 'g++'/'gcc'.
Une simple commande vous permet de préparer les fichiers dépendant de l'étape pour le td ou l'exercice :

```
mkdir build
cd build
```
```
cmake -DETAPE=2 -DTD=1 ..
```
_Dans cet exemple, l'étape 2 et le td 1 seront construits. Le tp lui n'a pas besoin de nombre particulier._

### Lancer la compilation

Il suffit ensuite de construire l'executable dans le dossier désiré

```
cmake --build . --target <target_name>
```
>`<target_name>` étant soit `td_insa`, `exercice_insa` ou `tp_insa`

## Conseil pour compiler et executer efficacement

Je vous suggère d'aller dans le dossier contenant l'executable dès que les deux étapes sont réalisées. Il vous suffit ensuite de lancer le script `.sh` ou `.bat` pour à la fois compiler et executer le code.

Pour cela rendez vous à la racine du projet après avoir crée et préparer le build :
```
./run.sh <target_name>
```
_Pour GNU GCC/G++ sur Linux_

```
./run.bat <target_name>
```
_Pour Powershell sur Windows_
```
run.bat <target_name>
```
_Pour CMD sur Windows_
>`<target_name>` étant soit `td_insa`, `exercice_insa` ou `tp_insa`

## Test des allocations entre la bibliothèque standard et mon implémentation

Voici le code testé :

```cpp
std::vector<int> vectStd;
Vector<int> vectYoyo;
int capacityStd(0), capacityYoyo(0);
size_t tempCapacityStd(0), tempCapacityYoyo(0);
for(int i=0; i<15000; i++)
{
    vectYoyo.PushBack(i);
    vectStd.push_back(i);
    if(tempCapacityStd != vectStd.capacity())
        capacityStd++;
    if(tempCapacityYoyo != vectYoyo.Capacity())
        capacityYoyo++;
    tempCapacityStd = vectStd.capacity();
    tempCapacityYoyo = vectYoyo.Capacity();
}
std::cout << "Total Yoyo Reallocations: " << capacityYoyo << "\tFinal Capacity: " << tempCapacityYoyo << std::endl;
std::cout << "Total Std Reallocations: " << capacityStd << "\tFinal Capacity: " << tempCapacityStd << std::endl;
```

Avec le résultat :

```
Total Yoyo Reallocations: 15    Final Capacity: 16384
Total Std Reallocations: 25     Final Capacity: 18207
```
Mon implémentation possède donc moins de réallocations, ainsi qu'une capacité finale moins grande. (Par comparaison, une simple implémentation augmentant la capacité `_capacity++` à chaque `push_back()` aurait autant de réallocation que de capacité finale. Bien qu'une capacité finale moins élevée.)