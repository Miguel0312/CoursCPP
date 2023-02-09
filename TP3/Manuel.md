# Analog

Analyse des fichiers contenant des logs Apache

## Utilisation:

Pour invoquer ce programme, il faut utiliser:

```
./analog [options] fichierDeLog
```

Les options possibles sont:

- -h: affiche le mode d'emploi du programme
- -g nomfichier.dot: génére un fichier au format GraphViz du graphe analysé
- -e: exclut tous les documents qui ont une extension d'image, css ou js
- -t heure: ne prend en compte que les logs dans [heure, heure+1[

Les extensions considerées comme des images sont .jpg, .png, .ico, .gif et .svg.

Pour créer le graphe a partir du fichier Graphviz court.dot et sauvegarder
l'image sur le fichier court.png, il faut utiliser:

```
dot -Tpng -o court.png court.dot
```

Pour éxecute les tests, il faut copier l'éxecutable après compilation et le
mettre en ./TestsLog/bin et ensuite éxecuter le script ./TestsLog/mktests.sh
