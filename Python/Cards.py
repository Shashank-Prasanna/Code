class Card:
    def __init__(self, suit ,number):
        self._suit = suit
        self.number = number

    def suit(self):
        return self.suit

    def __repr__(self):
        return self.number + " of " + self.suit


class Deck:

    def __init__(self):
        self.cards = []
        self.populate()
        print(self.cards)

    def populate(self):
        suits = ["hearts", "diamonds", "clubs", "spades"]
        numbers = [str(n) for n in range (2,11)] + ["J", "Q", "K", "A"]
        cards = []
        self.cards = [ Card(s,n) for s in suits for n in numbers ]

my_card=Card("6", "hearts")
print(my_card)
#my_deck = Deck()