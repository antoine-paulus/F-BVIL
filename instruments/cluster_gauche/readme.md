# Cluster Gauche 
Température des cylindres, réservoir gauche, ampèremètre, pression d'huile
## Disposition & Montage
* Le fichier stl est un standalone. 
* Les SG90 doivent être vissés, idem pour leurs aiguilles. Les leds peuvent être collées.
* Le cadran doit être directement vissé au tableau de bord.
* Pour le montage à l'avion, il sera peut-être necessaire de faire des trous dans la structure.

```Les aiguilles sont dans le dossier ../misc```

## Electronique
### Composants
* 4 leds de petite taille, blanches
* 4 moteurs servo type SG90
* 1 copie des fonds de cadrans
* 4 aiguilles servo
### Besoins
* 4 PWM pour les servos
* 4 alimentations 5V classiques (4 mâles)
* 4 alimentations leds TDB (4 femelles)
* 8 ground (4 mâles, 4 femelles)

## Calibration 
```Au 13/11/2021```
### Cyl head temp - Top Left:
* 67° (37%, 94) pour la valeur basse (<200)
* 0° (0%, 0) pour la valeur haute (>500)
### Left fuel - Top Right:
* 67° (37%, 94) pour la valeur basse (EMPTY)
* 0° (0%, 0) pour la valeur haute (FULL)
### Amperemètre - Bottom Left:
* 67° (37%, 94) pour la valeur basse (-20)
* 0° (0%, 0) pour la valeur haute (+20)
### Oil press - Bottom Right:
* 68° (38%, 96) pour la valeur basse (0)
* 0° (0%, 0) pour la valeur haute (>100)