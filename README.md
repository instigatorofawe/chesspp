# Chess++

A C++ chess library, using piece-centric bitmaps for board representation. Designed to interface with Chess engines via
the [Universal Chess Interface (UCI)](https://en.wikipedia.org/wiki/Universal_Chess_Interface). Written mostly for fun,
but potentially could be useful in parsing
[Portable Game Notation (PGN)](https://en.wikipedia.org/wiki/Portable_Game_Notation) and generating offline
reinforcement learning datasets (e.g. generating a table of positions for pre-training evaluation model for tree
search-based actor-critic).

## Contents

1. [Board representation](#board-representation)
1. [Planned features](#planned-features)
1. [Changelog](CHANGELOG.md)

## Board representation

Pieces are encoded as a 8x8x12 matrix of bool arrays (each layer represented by 64 booleans). One layer for each type of
piece (Pawn, Rook, Knight, Bishop, King, Queen) of each color. Occupancy can be determined by logical OR of all layers.
Vectorization/acceleration is achieved using OpenMP, and many of these matrix operations ore conducive to SIMD/AVX.

Additional elements of board state include castling (4 layers, 2 for each player castling queenside and kingside), en
passant (1 layer, with 1 indicating location of en passant if existing, 0s otherwise), active turn (1 layer), and number
of half-moves since last pawn push or capture, as after 50 moves the games results in a draw (1 layer).

Thus we have board state numerically represented as a 8x8x19 matrix, similar to the state representation for
[AlphaGo](https://www.nature.com/articles/nature16961), where different elements of state are encoded as separate
layers. This could prove convenient for convolutional neural network-based models, or may require substantial
modification of the code base at some later point.

Board state can also be parsed from
[Forsyth-Edwards Notation (FEN)](https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation).

## Planned features

1. Offline multiplayer with text interface
1. Interface with chess engines via UCI
1. Parser for FEN
1. Parser for PGN
1. Game library explorer
1. Heuristic-based engine using Monte Carlo Tree Search?
1. Actor-critic deep reinforcement learning based-engine with self-play training?