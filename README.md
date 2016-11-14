# DM Créer un emploi du temps en C++
##1) Description du projet

On souhaite vérifier les emplois du temps d’étudiants qui suivent différentes unités d’enseignement. Pour cela on dispose de deux types de fichiers:
* un fichier « étudiants » indiquant, pour chaque étudiant, quelles sont les unités suivies et possédant le format suivant :
```
nom_etudiant [ nom_UE1 nom_UE2 ... ]
```
  Les noms d’étudiants et les noms d’UE seront constitués d’une suite de lettres pouvant contenir, à partir du second caractère, des chiffres.

* un fichier « unités d’enseignement » indiquant, pour chaque UE, quels sont les jours et les horaires durant lesquels les enseignements sont dispensés et possédant le format suivant :
```
nom_UE1 [ créneauHoraire1 créneauHoraire2 ... ]
```
Les créneaux horaires sont définis par l’expression régulière suivante :
```
"(MO|TU|WE|TH|FR)@([\d]{1,2})-([\d]{1,2})"
```
Les groupes de 2 caractères représentent les abbréviations des noms des jours exprimés en anglais. Les nombres suivant le caractère ’@’ représentent l’heure de début et l’heure de fin qui seront toujours exprimées en heures pleines et devront respecter les contraintes suivantes :
  > 8 ≤ heure Début < heure Fin ≤ 19
Par souci de simplification, on ne fera pas de distinction entre cours, TD, TP et on considérera qu’un étudiant inscrit à une UE suivra TOUS les enseignements de ces UE et donc que, pour chaque étudiant, l’ensemble des créneaux horaires des UE suivies ne doit pas présenter d’intersections.

La détection de telles intersections est l’objectif du programme que vous développerez. Cette application ne possédera aucune interface graphique et sera utilisable en ligne de commande uniquement.

Elle devra produire, pour chaque étudiant présentant des intersections (chevauchements) entre les créneaux horaires des UE suivies, la liste des créneaux posant problème et la matière à laquelle ils sont rattachés.

Par exemple, à partir des données fournies en exemple, la sortie du programme donnera les informations suivantes :
```
Problems for paul:
-> english day: Wednesday start: 16 end: 18
conflicts with
-> french day: Wednesday start: 15 end: 17
Problems for sarah:
-> french day: Friday start: 9 end: 10
conflicts with
-> biology day: Friday start: 8 end: 10
Problems for tom:
-> physics day: Thursday start: 13 end: 15
conflicts with
-> math day: Thursday start: 14 end: 16
```

Dans le cas où aucune intersection ne sera détectée, l’application produira uniquement le message *OK*.

Lors de la lecture des fichiers « étudiants », l’application devra s’assurer :
* que le format général du fichier est respecté ;
* d’ignorer d’éventuels doublons dans la liste des UE suivies.

Lors de la lecture du fichier « unités d’enseignement », l’application devra s’assurer :
* que le format général du fichier est respecté notamment pour les créneaux horaires ;
* de la cohérence des créneaux horaires (abréviation du jour, heure de début, heure de fin) ;
* ignorer d’éventuels doublons dans la liste des créneaux horaires.
* qu’une UE suivie par au moins un étudiant possède bien une entrée dans ce fichier.
Tout problème rencontré lors cette phase de lecture devra conduire à la levée d’une exception indiquant le problème et l’arrêt de l’application.

##2) Contraintes de développement

L’application développée devra s’appuyer uniquement sur la bibliothèque standard de C++ :

* la lecture des fichiers s’effectuera avec la bibliothèque *iostream* et, en particulier, la classe *ifstream*;
* la lecture et la vérification des créneaux horaires pourra s’effectuer (mais ce n’est pas une obligation) avec la bibliothèque *regex*.

Penser à envisager des tests plus importants que ceux fournis par les fichiers donnés en exemple.
