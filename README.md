# 🏰 cub3D

> **cub3D** è un progetto della [Scuola 42](https://www.42.fr/) che introduce alla programmazione grafica e all'uso del raycasting per creare un motore grafico 3D ispirato al classico Wolfenstein 3D.

---

## 🎯 Obiettivo del Progetto

Creare un semplice motore grafico 3D usando il raycasting per renderizzare una mappa bidimensionale in uno spazio tridimensionale. L'obiettivo principale è comprendere i principi di base della grafica 3D e sviluppare un'applicazione grafica interattiva.

Il progetto è diviso in due parti principali:
1. **Parsing della mappa:** Analisi e gestione di un file `.cub` per caricare la mappa e i dati di configurazione.
2. **Motore grafico:** Implementazione del raycasting per generare una visuale 3D e gestire l'interazione con l'utente.

---

## 🛠️ Requisiti

### Software Necessario
- **Libreria MLX**: Una libreria grafica minima fornita dalla Scuola 42.
- **MinilibX**: Inclusa nel progetto per gestire finestre, immagini e input.
- **Makefile**: Deve essere in grado di compilare il progetto senza errori o avvisi.
- **C standard**: Il progetto deve essere conforme allo standard **C99** (o inferiore).

### Funzionalità Richieste
1. **Caricamento della mappa**:
   - Leggere un file `.cub` che definisce la mappa e altre impostazioni (texture, colori, ecc.).
   - Verificare che la mappa sia chiusa e valida.
2. **Raycasting**:
   - Implementare il rendering 3D della mappa usando il raycasting.
   - Calcolare correttamente le distanze e il campo visivo.
3. **Interazione**:
   - Muoversi nella mappa con i tasti WASD e le frecce.
   - Uscire dall'applicazione con il tasto `ESC`.
4. **Texture e colori**:
   - Applicare texture alle pareti.
   - Gestire il colore del soffitto e del pavimento.
5. **Gestione degli errori**:
   - Riconoscere e gestire errori nei file `.cub`.

---

## 📂 Compilazione

```plaintext
git clone https://github.com/tuo-username/cub3D.git
cd cub3D
make
./cub3D maps/*.cub

