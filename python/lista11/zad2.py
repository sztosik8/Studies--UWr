from sqlalchemy import create_engine, Column, Integer, String, ForeignKey
from sqlalchemy.orm import declarative_base, relationship, Session
import argparse

Base = declarative_base()

class Utwor(Base):
    __tablename__ = 'utwory'

    id = Column(Integer, primary_key=True)
    tytul = Column(String, nullable=False)
    rok_powstania = Column(Integer, nullable=True)

    # Relacja one-to-many z wykonawcami
    wykonawcy = relationship('Wykonawca', back_populates='utwor')

class Wykonawca(Base):
    __tablename__ = 'wykonawcy'

    id = Column(Integer, primary_key=True)
    nazwa = Column(String, nullable=False)
    
    # Relacja one-to-many z utworami
    utwor_id = Column(Integer, ForeignKey('utwory.id'))
    utwor = relationship('Utwor', back_populates='wykonawcy')

class Muzyk(Base):
    __tablename__ = 'muzycy'

    id = Column(Integer, primary_key=True)
    imie = Column(String, nullable=False)
    nazwisko = Column(String, nullable=False)

    # Relacja one-to-many z utworami
    utwor_id = Column(Integer, ForeignKey('utwory.id'))
    utwor = relationship('Utwor', back_populates='muzycy')

# Funkcje do obsługi operacji dodawania, aktualizacji i wyszukiwania
def dodaj_utwor(session, tytul, rok_powstania):
    nowy_utwor = Utwor(tytul=tytul, rok_powstania=rok_powstania)
    session.add(nowy_utwor)
    session.commit()

def wypisz_utwory(session):
    utwory = session.query(Utwor).all()
    for utwor in utwory:
        print(f"Tytuł: {utwor.tytul}, Rok powstania: {utwor.rok_powstania}")

def main():
    engine = create_engine('sqlite:///baza_danych.db', echo=True)
    Base.metadata.create_all(engine)
    
    SessionClass = Session(bind=engine)
    session = SessionClass()

    parser = argparse.ArgumentParser(description='System przechowujący informacje o utworach muzycznych.')
    parser.add_argument('operacja', choices=['dodaj', 'wypisz'], help='Operacja do wykonania')
    parser.add_argument('--tytul', help='Tytuł utworu')
    parser.add_argument('--rok', type=int, help='Rok powstania utworu')

    args = parser.parse_args()

    if args.operacja == 'dodaj':
        dodaj_utwor(session, args.tytul, args.rok)
    elif args.operacja == 'wypisz':
        wypisz_utwory(session)

if __name__ == '__main__':
    main()
