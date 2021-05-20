# Cahier de suivi du projet de Xuan Huong HUYNH PHUC

- Séance du 22 mars 2021 (séance de brainstorming):

Anas EL GANA et moi avions décidé de former un binôme afin de réaliser le projet du masque connecté. Je lui ai expliqué le concept du projet. On a vérifié auprès des enseignants sur la disponibilité de matériel. 

- Séance du 29 mars : 

On a confirmé notre projet auprès des enseignants. Je me suis occupée du circuit de l'alimentation et des capteurs. J'ai cherché les différents options pour les tests. L'idée de départ est d'utiliser la pression pour déclencher un timer (durée 4h) qui permet de rappeler à l'utilisateur de changer le masque. On a testé avec le capteur TEMT6000 en attendant d'avoir les capteurs dont nous avions besoins.

- Séance du 05 avril :

J'ai monté le circuit. J'ai identifié les capteurs et fait des recherches pour trouver les codes à utiliser sur Arduino. J'ai imaginé un système de pince reliant les capteurs pour accrocher sous le masque.

- Séance du 12 avril :

J'ai montré les codes à mon binôme et fait vérifer par les enseignants. Les codes sont fonctionnels mais on avait un problème de circuit. J'ai changé de carte, de board puis les fils pour identifer le problème.(Problème résolu)

- Le 18 avril :

J'ai fais tester le masque à quelques personnes de ma famille (mon neveu 18 ans, mon frère 40 ans) qui ont bien voulu garder pendant quelques minutes. Je voulais voir par rapport à la tranche d'âge de chaque personne, les variations des paramètres. N'ayant pas pu tester plus longtemps, j'ai abandonné l'idée de classer par tranche d'âge.
J'ai crée sur tinkercad une maquette de boîte pour le circuit.

- Séance du 19 avril : 

On a réfléchi à comment combiner les 2 codes et alléger les codes pour rendre le programme éxécutable.  J'ai montré à mon binôme les tests effctué sur mes "cobayes" et la maquette du boîtier avec un sytème d'accroche. Le fablab n'ayant pas de superviseur, je n'ai pas pu imprimer la boîte.

![boitier 3D](https://user-images.githubusercontent.com/84131336/118410563-5f93ce00-b690-11eb-84e2-05bcba671fd4.PNG)
![boitier 3D(2)](https://user-images.githubusercontent.com/84131336/118410581-6f131700-b690-11eb-9592-748f759b7120.PNG)


- Séance du 26 avril : 

Le circuit et les codes sont fonctionnels. Node red nous pose problème. On a réfléchi à comment intégrer les nouvelles variables sur node en complétant nos codes. J'ai récupéré le circuit afin de faire des tests sur les différents types de masque.

- Le 03 mai :

Je me suis procurée différents types de masque qu'il existe sur le marché afin de commencer les tests. J'ai débuté par le masque en tissu simple puis celui en tissu avec filtre et celui en tissu avec "filtre café". J'ai rectifié le délai pour les relevés. 
Je me suis procurée une tête de mannequin pour placer le masque et le circuit. Cela m'a permis de réfléchir à comment placer le boitier et les capteurs sur le masque.

- Le 08 mai :

N'ayant pas pu créer mon boîtier, j'ai eu l'idée de le créer à l'aide d'un stylo 3D. Les premiers essais n'étaient pas top mais j'ai réussi à fabriquer le boîtier.

![Boîtier S3D](https://user-images.githubusercontent.com/84131336/118410907-278d8a80-b692-11eb-89d6-c025b0b355f3.PNG)

J'ai ensuite continué à faire les tests avec un masque en tissu néoprène puis avec le masque chirurgical.

- Le 09 mai :

J'ai testé le masque chirugical pendant l'effort mais malheureusement le capteur de la qualité de l'air a rendu l'âme au bout de 13 minutes et il n'y avait plus de relevé. En activté, la chaleur et la condensation de l'humidité a rendu unitilisable le capteur.

J'ai cherché par rapport au seuil limite de la quantité de CO2 afin de trouver les valeurs limites pour créer les alertes sur node red.

- Le 10 mai :

Réunion avec mon binôme pour lui donner le circuit et montrer les tests effectués. Je lui ai expliqué l'incident du capteur CCS. Je lui ai donné les valeurs limtes des paramètres pour les alertes. On a rediscuté par rapport à l'avancement et de la suite des tâches de chacun.

- Le 11 mai :

J'ai regroupé tous les relevés des test puis trié afin de chercher les variations significatives paramètres à utiliser dans les alertes. J'ai réuni tous les fichiers sur excell et tracé les graphes.

- Le 12 mai :

Suite au problème du capteur dysfonctionnel, mon binôme m'a fait part que le code ne marchait plus. Je lui ai demandé d'utiliser le capteur TEMT6000 qu'on avait sous la main pour continuer à tester sur node.

- Le 13 mai :

J'ai envoyé par message à mon binôme les codes des triggers sur node afin qu'il les teste. J'ai crée le répertoire sur github et commencer à éditer notre projet. J'ai essayé de poster une photo sur la page principale.

- Le 16 mai :

J'ai remis au propre et comparer les tests effécutés. J'ai fait des recherches sur les risques liés à l'exposition d'une forte quantité de CO2 sur la santé.
J'ai commencé à faire les slides pour la présentation finale et à déposer mes tests et travaux sur github.

- Le 17 mai :

J'ai du me rendre à la fac car mon binôme n'arrivait pas à faire marcher le circuit. Je l'ai aidé à chercher le problème puis j'ai continué faire les slides de présentation. Ce soir, mon binôme m'a envoyée les derniers code sur node et les screens pour que je puisse finir le github et la présentation finale du projet.
Le github est presque fini plus qu'à rajouter les présentations intermédiare et finale.
J'ai rajouté la partie de node red sur la présentation finale.

- Le 18 mai :

J'ai terminé les slides pour la présentation finale à l'oral. Je vais envoyer le fichier à mon binôme pour qu'il voie s'il y a des modifications à apporter.

- Le 20 mai:

J'ai fait des dernières photos pour la page de présentation. J'ai cherché à comment positionner le boitier pour la présentation finale du projet. J'ai déposé les sildes de la présentationfinale sur github.

![masque présentation](https://user-images.githubusercontent.com/84131336/119029283-bbb86400-b9a8-11eb-827d-96d3271d4f5b.jpg)
