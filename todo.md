# Parsing:

Elementi del File di Configurazione:

RISOLUZIONE: Definisce la risoluzione della finestra di gioco.
```
R 1920 1080
```
TEXTURE: Percorsi verso le immagini delle texture per le pareti, il soffitto e il pavimento.

	NO ./path_to_the_north_texture
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture
	S  ./path_to_the_sprite_texture

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

    - [ ] Implementa il parsing della risoluzione
    - [ ] Implementa il parsing delle texture
    - [ ] Implementa il parsing dei colori
    - [ ] Implementa il parsing della mappa

PSEUDOSTRUCT:
```
function parse_file(filename):
    open file
    for each line in file:
        if line starts with "R ":
            parse_resolution(line)
        else if line starts with "NO " or "SO " or "WE " or "EA " or "S ":
            parse_texture(line)
        else if line starts with "F " or "C ":
            parse_color(line)
        else:
            parse_map(line)
    close file

function parse_resolution(line):
    // Estrai e valida la risoluzione

function parse_texture(line):
    // Estrai e valida il percorso della texture

function parse_color(line):
    // Estrai e valida il colore

function parse_map(line):
    // Aggiungi la linea alla matrice della mappa
```
