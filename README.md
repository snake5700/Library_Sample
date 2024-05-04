# Specifica del progetto.

Si supponga di dover costruire un sistema software gestionale per una o più catene di librerie anche presenti in più località del globo, tranne dove la loro costruzione non è stata autorizzata. Il sistema deve essere in grado di identificare le **catene** mediante il loro _nome_, il _numero di librerie_ aperte per catena e il _CEO_ di queste. Le **librerie** inserite all'interno delle catene devono essere identificate dal loro _nome_, la _località_ in cui è situata, la _data apertura_ e il _gestore_. Il **gestore** a sua volta dovrà essere identificato da un _identificativo_. I **libri** tenuti dalle librerie sono identificati mediante l'_autore_, il _titolo_, l'_isbn_, il _prezzo_ e dal _numero di copie_ presenti in negozio; se vengono **prestati** deve essere immessa un'istanza di prestito contenente la _data_, l'_ora_, la _libreria_ in cui è stato effettuato, la _data-scadenza_ e l'_identificativo_ del richiedente; mentre, per la **vendita** si tiene traccia della _data_ di vendita, del _prezzo_ e l'_identificativo_ dell'acquirente. I **clienti** delle librerie dovranno essere registrati all'interno del sistema e identificati tramite una **tessera**, sulla quale andranno inseriti il _codice fiscale_, la _libreria_ emittente, la _data-scadenza_ della tessera e il _numero di multe_ a suo carico. Le **multe** emesse a chi non ha rispettato il termine del prestito sono identificate da un _identificativo_, la _libreria emittente_, l'_importo_ dovuto e la sua _scadenza_.  

Vincoli: 

- I gestori di una libreria possono non essere tesserati per le librerie facenti parte della stessa catena, inoltre hanno diritto ad uno sconto del 20% sul prezzo di tutti i libri presenti nel catalogo;
- Non è possibile prendere in prestito un libro senza essere stati registrati all'interno del sistema ed aver ricevuto la propria tessera;
- Se il cliente ha ricevuto una multa per la mancata restituzione non potrà prendere più prendere prestito libri nelle librerie della stessa catena, inoltre il mancato pagamento di questa comporta la sospensione della tessera fino al ricevimento del dovuto.


# In Aggiornamento.
