DROP DATABASE IF EXISTS game;
CREATE DATABASE game;
USE game;
CREATE TABLE player(
 Identificador  INTEGER NOT NULL,
 Name TEXT NOT NULL,
 Pass TEXT NOT NULL,
 Wingame INTEGER NOT NULL,
 Losegame INTEGER NOT NULL,
 PRIMARY KEY (Identificador)
)ENGINE = InnoDB;
CREATE TABLE games(
 Identificador INTEGER NOT NULL,
 Winnername TEXT NOT NULL,
 Time INTEGER NOT NULL,
 fecha TEXT NOT NULL,	
 PRIMARY KEY (Identificador)
)ENGINE = InnoDB;

CREATE TABLE relations(
 idplayer INTEGER,
 idgame INTEGER,
 points INTEGER NOT NULL,
 FOREIGN KEY (idplayer) REFERENCES player(Identificador),
 FOREIGN KEY (idgame) REFERENCES games(Identificador)
)ENGINE = InnoDB;

INSERT INTO  player Values(1,'Ascanio','pica',7,0);
INSERT INTO  player Values(2,'Tamariz','pica',9,4);
INSERT INTO  player Values(3,'Daortiz','pica',1,1);

INSERT INTO  games Values(1,'Ascanio',38,'2/12');
INSERT INTO  games Values(2,'Daortiz',46,'17/12');
INSERT INTO  games Values(3,'Ascanio',39,'11/12');

INSERT INTO  relations Values(1,1,32);
INSERT INTO  relations Values(2,1,46);
INSERT INTO  relations Values(3,1,12);
INSERT INTO  relations Values(1,2,89);
INSERT INTO  relations Values(2,2,37);
INSERT INTO  relations Values(3,2,2);
INSERT INTO  relations Values(1,3,11);











