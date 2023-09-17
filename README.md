# Module C++ INSA 4AE

## Compiler le projet

### Préparer la compilation

Pour compiler le projet je recommande CMake, mais il est possible d'utiliser directement 'g++'/'gcc'.
Une simple commande vous permet de préparer les fichiers dépendant de l'étape :

```
mkdir build
cd build
```
```
cmake -DETAPE=2 ..
```
_Dans cet exemple, l'étape 2 sera construite._

### Lancer la compilation

Il suffit ensuite de construire l'executable dans le dossier désiré

```
cmake --build .
```

## Conseil pour compiler et executer efficacement

Je vous suggère d'aller dans le dossier contenant l'executable dès que les deux étapes sont réalisées. Il vous suffit ensuite de lancer le script `.sh` ou `.bat` pour à la fois compiler et executer le code.

Pour cela rendez vous à la racine du projet après avoir crée et préparer le build :
```
./run.sh
```
_Pour GNU GCC/G++ sur Linux_
```
run.bat
```
_Pour MSVC sur Windows_