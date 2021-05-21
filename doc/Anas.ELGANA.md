# Cahier de suivi du projet de EL GANA ANAS

- 1ére étape:

faisabilité du projet avec les profs, disponibilité du materiel dans le laboratoire et suddivision des tâches



J'ai cherché les bibliotheques pour les différents capteur pour faire les tests (ccs811, bme280) et puis j ai fais des test et noté les données trouvées

Puis j ai essayer de combiner les 2 codes des capteur pour pouvoir avoir un seul code géneral, aprés plusieurs échec dû à des problemes comme les libraries j ai reussi mais il y avait un dernier souci, envoyer les données sur NODE-RED


Apres avoir cherché dans des forum des solutions(en anglais!!)j ai reussi grâce à mes experience en programmation sur C++ à comprendre que je devais manipuler la fonction do_send() et après plusieurs jours d'essaie j'ai reussi à envoyer les premiers resultat, même si avec de difficulté, en modifiant la fonction do_send avec l'array contenent les information, dans notre cas mydata[]



En suite grâce au server csf presente sur le TTN j'ai reussi à prendre les donnes depuis arduino et les avoir sur un server, NODE-RED
 

Grâce aux differents fonctions j ai pu prendre le valeur de chaque capteur et de pouvoir les afficher grâce à la palette contrib-ttn et un un debug message mais les problemes venaient de commencer.


J'ai perdu beaucoup de temps avec l'email car nous avons utilisé le serveur de gmail.com et pas de unice.fr comme dans le TP et donc forcement il y a plus de problemes lieés à la securité avec smtp.gmail.com  


J'ai ensuite fais de recherche sur comment configurer exactement le serveur gmail et aprés plusieurs tentatives j ai reussi à le faire marcher en faisant une mot de passe juste pour les application et cela a marché!


Il y avait un dernier probleme, à chaque control des fonction NODE-RED envoyé l'email même si le masque était encore utilisable, et ça c'etait un gros probleme car on pouvait pas remplir la boite de reception à chaque fois donc pour cela j ai créer dess fonction alarm qui envoyé l'email seulement quand la condition est true et donc j ai fais en mode qu il envoie seulment quand il depasse certain valeurs trouver par mon collegue

J'ai cherché en suite un moyenne de faire un autre genre de notification car l'email oui c'est un bon outil mais pas toujours pratique!.



Après des recherches je suis tombé sur le site twilio.com qui permet de faire plein de projet dans mon cas je me suis reinsegné sur la partie Programmable Messaging Logs
qui est gratuit en version TRIAL.

En suite après avoir installé la palette lié à twilio j ai pu inserer les donné concernant la configuration mobile avec un TOKEN, ACCOUNT SID et enfin un VOIP voice overIP un tout à fait numero de telephone qui me permet d'envoyer à n'importe qui un message, seulement à des numero verifié pour la version TRIAL.

Puis j'ai fais en sorte de pouvoir modifier à mon goût le message grâce au msg.payload et de pouvoir recevoir le message en modifiant la même fonction utilisé pour l'email


Après cela j'ai fais mes test presents dans la presentation finale et j'ai données le materiel fini à mon collegue pour discuter de comment faire l'oral et de comment assembler tout les données acquis pendant le projet.


