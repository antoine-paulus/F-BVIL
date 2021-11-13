# Cadran Manifold pressure, Fuel Flow, RPM
## Disposition & Montage
* Les deux cadrans sont à visser/coller au ring
* Le cadran MP/FF est disposé à gauche, les trous pour les leds sur le dessus.
* Les composants doivent être vissés pour les servos moteurs, et clipsés pour les leds et le moteur pas à pas
* Pour le montage à l'avion, il est nécessaire de faire 8 trous de 3 mm sur le ring.

```Les aiguilles sont dans le dossier ../misc```

## Electronique
### Composants
* 4 leds de petite taille, blanches
* 2 moteurs servo type SG90
* 1 moteur pas à pas type 28BYJ-48 et son PCB
* 1 copie des fonds de cadrans
* 2 aiguilles servo
* 1 aiguille pas à pas 
### Besoins
* 2 PWM pour les servos
* 4 broches digitales pour le moteur pas à pas
* 3 alimentations 5V classiques (2 mâles, 1 femelle)
* 4 alimentations leds TDB (4 femelles)
* 7 ground (2 mâles, 5 femelles)

## Calibration
### Manifold pressure (cadran 1, Gauche):
* 180° (100%, 255) pour la valeur haute (>35 Hg)
* 0° (0%, 0) pour la valeur basse (<10 Hg)
### Fuel Flow (cadran 2, Gauche):**
* 0° (0%, 0) pour la valeur haute (>20)
* 180° (100%, 255) pour la valeur basse (<0)
### RPM (cadran droit)**
* 2048 impulsions par tour. A calibrer directement sur mobiflight.