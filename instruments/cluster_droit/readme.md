# Cluster Droit
Réservoir droit, température d'huile.
## Disposition & Montage
* Le fichier stl est un standalone. 
* Les SG90 doivent être vissés, idem pour leurs aiguilles. Les leds peuvent être collées.
* Le cadran doit être directement vissé au tableau de bord.
* Pour le montage à l'avion, il sera peut-être necessaire de faire des trous dans la structure.

```Les aiguilles sont dans le dossier ../misc```

## Electronique
### Composants
* 2 leds de petite taille, blanches
* 2 moteurs servo type SG90
* 1 copie des fonds de cadrans
* 2 aiguilles servo
### Besoins
* 2 PWM pour les servos
* 2 alimentations 5V classiques (2 mâles)
* 2 alimentations leds TDB (2 femelles)
* 4 ground (2 mâles, 2 femelles)

## Calibration 
```Au 13/11/2021```
### Right fuel - Top :
* 67° (37%, 94) pour la valeur basse (EMPTY)
* 0° (0%, 0) pour la valeur haute (FULL)
### Oil temp - Bottom:
* 67° (37%, 94) pour la valeur basse (0)
* 0° (0%, 0) pour la valeur haute (245)
