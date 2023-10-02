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
_Dans cet exemple, l'étape 2 et le td 1 seront construits._

### Lancer la compilation

Il suffit ensuite de construire l'executable dans le dossier désiré

```
cmake --build . --target <target_name>
```
>`<target_name>` étant soit `td_insa` ou `exercice_insa`

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
>`<target_name>` étant soit `td_insa` ou `exercice_insa`