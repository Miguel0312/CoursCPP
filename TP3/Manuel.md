 # Analog
Analyse des fichiers contenant des logs Apache

 ## Utilisation:
 Pour invoquer ce programme, il faut utiliser
 
 <center>
 ./analog [options] fichierDeLog
 </center>
 
 Les options possibles sont:
- -h: affiche ce texte
- -g nomfichier.dot: génére un fichier au format GraphViz du graphe analysé
- -e: exclut tous les documents qui ont une extension d'image, css ou js
- -t heure: ne prend en compte que les logs dans [heure, heure+1[

Les extensions considerees comme des images sont .jpg, .png, .ico, .gif et .svg.

Pour creer le graphe a partir du fichier Graphviz, il faut utiliser
<center> dot -Tpng -o court.png court.dot </center> 
