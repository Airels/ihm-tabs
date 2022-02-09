# Sujet:

Cette application permettra d’afficher des données matricielles générées aléatoirement ou provenant
de fichiers de données CSV, XLSX ou autres formats sous une forme tabulaire. Un premier affichage
sous forme tabulaire sera présenté à l’utilisateur. Ce dernier pourra ordonner les lignes suivant les
valeurs de la colonne de son choix et il pourra aussi choisir plusieurs colorations dépendantes des
valeurs des cellules. Ce type d’affichage est limité en nombre de lignes et de colonnes. Pour
outrepasser cette limite, une abstraction des données est nécessaire. Tout en conservant les
possibilités d’interactions d’ordonnancement et de choix de couleurs, l’affichage ne se fera plus sous
la forme d’un tableau de valeur mais en une image dont chaque pixel représentera la valeur d’une
donnée. Suivant la taille des données, une donnée pourra correspondre à plusieurs pixels ou, à
l’inverse, un pixel pourra représenter plusieurs données. Un export de l’image en bitmap (PNG, BMP…)
et/ou en vectoriel (SVG) sera apprécié accompagné de la description des données (nom du fichier,
nombre de lignes et de colonnes, date de l’export…).
Pour éviter toute confusion concernant la coloration et pour une colonne donnée, toutes les valeurs
identiques auront la même couleur et toutes les valeurs différentes auront des couleurs différentes.

# Auteurs principaux

- BRICOUT Titouan
- IKHLEF Eddy
- NICOLAï Guillaume
- VICAÏNO Yohan

# Utilisation

A l'ouverture de l'application, via le menu contextuel vous pourrez :
- Ouvrir un fichier (csv, ou .ITabs, format créer pour le projet et pour sauvegarder)
- Générer des données (Taille de la matrice de donnée, valeur min et max optionelles)

Après avoir ouvert des données, via le menu contextuel vous pourrez :
- Ouvrir un fichier (csv, ou .ITabs, format créer pour le projet et pour sauvegarder)
- Fermer le fichier ouvert (retour à la fenêtre à l'état initiale)
- Sauvegarder les données (sous format .ITabs, permettant de sauvegarder la structure et les filtres appliqués aux cellules)
- Exporter les données (sous format .bmp, .jpeg, .png)
- Générer des données (Taille de la matrice de donnéess, valeur min et max optionelles)

Après avoir ouvert des données, via l'interface vous pourrez :
- Visualisez les données sous forme de tableau et/ou sous forme d'image
- Selectionnez des valeurs (ou toutes les valeurs)*
- Trier des valeurs**
- Selectionnez un filtre, le paramétrer et l'appliquer sur les valeurs séléctionées

>\* Il est possible de séléctionner toute une colonne ou une ligne en cliquant sur l'entête des colonnes ou des lignes du tableau (simple clique)
\*\ Il est possible de trier les valeurs du tableau d'une colonne en double cliquant sur l'entête des colonnes du tableau (double clique)

# Ressources
## Sources
Le code source est trouvable dans le dossier /src

## Scénarios et jeux de tests
Des jeux de tests ainsi que des scénarios à appliquer sont trouvable dans le dossier /scenarios
Un document annexe permettant en détail de visualiser chaque étape du scénario avec image est trouvable dans le dossier /annexes

## Les diagrammes de cas d’utilisation et de navigation ainsi que la modélisation des IHM et leurs événements émis et les slots d’interception
Un document contenant les diagrammes de cas d’utilisation et de navigation ainsi que la modélisation des IHM et leurs événements émis et les slots d’interception est trouvable dans le dossier /annexes
