# Simulation Physique du Comportement de Gaz Parfaits dans une Enceinte

## Table des Matières

- [Aperçu du Projet](#aperçu-du-projet)
- [Utilisation](#utilisation)
- [Contribution](#contribution)
- [Contact](#contact)

## Aperçu du Projet

### Progression
#### Sur 12 semaines de travail, avec en moyenne 5 heures de travail par personne par semaine :

* **Réalisé** :
  * Représentation physique de vecteurs, de différents types de particules et d'enceintes en 3 dimensions.
  * Méthodes de calcul et de déplacement de particules dans un système fermé faisant intéragir les particules entre elles, et avec les parois d'une enceinte.
  * Implementation des fonctionalités d'affichage des objets du système sur un support; premier pas pour le graphisme.
  * Simulation textuelle avec affichage des positions et vitesses des particules ainsi que les interactions qui leur arrivent.
  * Fonctionalité d'initialisation d'un système thermodynamique en respectant la distribution de Maxwell.
  * Optimisation calculatoire de la collison entre particules par représentation spatiale de "cases" occupées ou non par des particules.
  * Suivi d'une particule, sauvegardant sa trajectoire sous forme textuelle dans un fichier.

* **À faire** :
  * Interface graphique d'un système.
  * Optimisation des performances
  * Fonctionalités spéciales telle que la possibilité d'interaction avec le système pendant l'évolution, la récolte de données physiques du système et la vérification des lois de la thermodynamique.
  * Et encore...

## Utilisation

### Instructions d'Installation
1. **Cloner le Dépôt** :
   ```bash
   git clone https://github.com/jayse15/Projet_POO.git
   cd Projet_POO
   ```

2. Pas de dépendances à installer, le programme tourne sur C++11.

### Organisation des Classes
Le projet est structuré autour de plusieurs classes principales :

Représentation physique :
* **Vecteur3D** : Représente un vecteur dans l'espace tridimensionnel. Utilisée pour la vitesse et la position d'une particule.
* **Particule** : Classe de base pour les particules, contenant des méthodes pour l'affichage, le déplacement et la collision d'une particule avec un autre. On y trouve aussi les sous-classes de **Particule** (**Néon**, **Argon**, **Hélium**).
* **Enceinte** : Représente l'espace tridimensionnel dans lequel évoluent les particules.
* **Systeme** : Contient et gère les particules ainsi que l'enceinte. Inclut des méthodes pour calculer les interactions et les déplacements d'un ensemble de particules. Se trouveront ici les méthodes pour faire une simulation physique.
* **Grid** : Sous-classe de **Systeme**, est une représentation spatiale de cases qui est plus optimale pour la collision entre particules.
* **GenerateurAleatoire** : Utilisée pour générer aléatoirement des nombres.

Représentation graphique:
* **Dessinable** : Super-classe virtuelle caractérisant tous les objets qui pourront être affiché graphiquement.
* **SupportADessin** : Super-classe virtuelle caractérisant tous les suports d'affichage possible.
* **TextViewer** : Sous-classe de **SupportADessin**, affichage texte simple.
* **Brownien** : Sous-classe de **TextViewer**, utilisé pour le suivi d'une particule.

### Make et Tests
Pour tester les fonctionnalitées, nous vous recommandons de faire comme suit:

* Les méthodes utilisées dans les fichiers test sont les seules qu'un utilisateur aurait besoin pour une simulation. Nous vous recommandons d'utiliser que celles ci.
* Pour construire les liens et créer les fichiers executables nous avons crée un Makefile. la commande :
  ```bash
  make classe_name
  ```
  va créer les fichiers .o nécessaires et le fichier executable **classe_name** qui va run le main du fichier **testclasse_name.cc**. Il reste plus qu'à faire la commande :
  ```bash
  ./classe_name
  ```
  et le programme s'éxecutera.
* Vous pouvez aussi run les fichiers **exerciePX.cc** avec :
  ```bash
  make exercicePX
  ```
  et :
  ```bash
  ./exercicePX
  ```
* Attention ! Le Makefile a actuellement des problèmes et ne crée pas d'exectuable lors de la commande :
  ```bash
  make Grid
  ```



## Contribution
 Les contributions sont les bienvenues ! Veuillez suivre ces étapes pour contribuer :

1. **Forker le dépôt :**
   Cliquez sur le bouton "Fork" en haut de la page du dépôt pour créer une copie du dépôt sur votre compte GitHub.

2. **Créer une branche pour votre fonctionnalité ou correction :**
   ```bash
   git checkout -b nom-de-votre-branche
   ````
3. **Faire un commit de vos modifications :**
   ```bash
   git commit -m 'Ajout de la fonctionnalité X'
   ```
4. **Pusher votre branche :**
   ```bash
   git push origin nom-de-votre-branche
   ```
5. **Ouvrir une Pull Request :**
Allez sur le dépôt d'origine sur GitHub et cliquez sur "New Pull Request".


## Contact

Jason Grieder - jason.grieder@epfl.ch
Alban Sibileau - alban.sibileau@epfl.ch

Lien du Projet : https://github.com/jayse15/Projet_POO
