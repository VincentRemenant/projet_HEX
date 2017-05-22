-- mettre en place la base de données

CREATE TABLE joueur
(
	pseudo VARCHAR2(100) PRIMARY KEY NOT NULL,
	email VARCHAR2(100),
	date_de_naissance DATE
);

CREATE TABLE partie
(
	code_partie NUMBER(3) PRIMARY KEY NOT NULL,
	date_partie DATE,
	joueur1 VARCHAR2(100),
	joueur2 VARCHAR2(100),
	gagnant VARCHAR2(100),
	CONSTRAINT fk_partie_joueur1 FOREIGN KEY(joueur1) REFERENCES joueur(pseudo),
	CONSTRAINT fk_partie_joueur2 FOREIGN KEY(joueur2) REFERENCES joueur(pseudo),
	CONSTRAINT fk_partie_gagnant FOREIGN KEY(gagnant) REFERENCES joueur(pseudo)
);

CREATE TABLE coup
(
	partie NUMBER(3),
	joueur VARCHAR2(100),
	tour NUMBER(3),
	case VARCHAR2(2),
	CONSTRAINT fk_coup_joueur FOREIGN KEY(joueur) REFERENCES joueur(pseudo),
	CONSTRAINT fk_coup_partie FOREIGN KEY(partie) REFERENCES partie(code_partie),
	CONSTRAINT pk_coup PRIMARY KEY (partie,joueur)
);

-- exemples de peuplement

INSERT INTO joueur VALUES ('Romain','romain@mail.com','01/02/0304');
INSERT INTO joueur VALUES ('Vincent','vincent@mail.com','05/06/0708');
INSERT INTO partie VALUES (1,'09/10/1112','Romain','Vincent','Romain');
INSERT INTO partie(code_partie,date_partie,joueur1,joueur2) VALUES (2,'13/02/1516','Romain','Vincent');
INSERT INTO coup VALUES (1,'Romain',1,'A1');
INSERT INTO coup VALUES (1,'Vincent',2,'B2');

-- retrouver les parties effectuées par un joueur à une date donnée

SELECT *
FROM partie
WHERE date_partie = '09/10/1112'
AND (joueur1 = 'Romain'
OR joueur2 = 'Romain');

-- toutes les parties effectuées par un joueur

SELECT *
FROM partie
WHERE (joueur1 = 'Romain'
OR joueur2 = 'Romain');

-- retrouver les parties gagnées par un joueur

SELECT *
FROM partie
WHERE gagnant = 'Romain';

-- retrouver les parties abandonnées auxquelles a participé un joueur

SELECT *
FROM partie
WHERE gagnant IS NULL
AND (joueur1 = 'Romain'
OR joueur2 = 'Romain');

-- retrouver les joueurs rencontrés par un joueur donné

SELECT pseudo
FROM joueur j, partie p
WHERE (j.pseudo = p.joueur1
AND p.joueur2 = 'Romain')
OR (j.pseudo = p.joueur2
AND p.joueur1 = 'Romain');

-- retrouver les parties débutée par un coup donné

SELECT p.*
FROM partie p, coup c
WHERE c.tour = 1
AND c.joueur = 'Romain'
AND c.case = 'A1'
AND c.partie = p.code_partie;
