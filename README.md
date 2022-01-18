# Sujet

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
