# Parsing:

Elementi del File di Configurazione:

TEXTURE: Percorsi verso le immagini delle texture per le pareti, il soffitto e il pavimento.

	NO ./path_to_the_north_texture
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture

COLORI: Colori del cielo e del pavimento in formato RGB.
```  
F 220,100,0
C 225,30,0
```
MAPPA:

- La mappa è rappresentata come una griglia di caratteri dove ogni carattere ha un significato specifico:
```
    0: Spazio vuoto (camminabile).
    1: Muro.
    2: Sprite (oggetto interattivo o decorazione).
    N, S, E, W: Posizione iniziale del giocatore e la direzione in cui guarda (Nord, Sud, Est, Ovest).
```
- Validazione della Mappa:

  - La mappa deve essere chiusa (non ci devono essere buchi nei muri che permettano di uscire dalla mappa).
  - La mappa deve avere esattamente una posizione iniziale del giocatore.

ERROR HANDLING...

- PARSING IMPLEMENTATION:

    - [ ] Implementa il parsing delle texture
    - [ ] Implementa il parsing dei colori
    - [ ] Implementa il parsing della mappa


# MLX:

- mlx_init()
- mlx_new_window
- mlx_xpm_file_to_image
- mlx_put_image_to_window
- mlx_key_hook(key_hook->close_window)
- mlx_hook(close_window)
- mlx_loop

# RAYCASTING

Step 1: Calculating the Ray Direction
The first step in the raycasting algorithm is to calculate the direction of the ray based on the player’s position and orientation.
Step 2: Calculating the Delta Distance
The next step in the raycasting algorithm is to calculate the delta distance between two consecutive x or y intersections with a grid line.
Step 3: Calculating the Step and Initial Side Distances
Now we need to calculate the step_x, step_y and the initial side distances for the ray. The step_x and step_y variables determine the direction in which the ray moves through the grid
Step 4: Performing Digital Differential Analysis
The next step in the raycasting algorithm is to perform Digital Differential Analysis (DDA) to determine the distance to the next grid line in the x or y direction. This involves stepping through the grid and calculating the distance to the next grid line in each direction
Step 5: Calculating the Wall Height
The final step in the raycasting algorithm is to calculate the height of the wall based on the distance to the wall and the player’s view.