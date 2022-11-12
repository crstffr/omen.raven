#define NUM_MUSIC_NOTES 12
#define NUM_MUSIC_SCALES 40
#define NUM_SCALE_INTERVALS 12
#define NUM_MUSIC_KEYS 26
#define NUM_MUSIC_KEY_CHORDS 7
#define NUM_MUSIC_CHORDS 73
#define NUM_CHORD_NOTES 6

RavenMenuOption musicNoteOptions[NUM_MUSIC_NOTES] = {
  {0,  (char *)"C"},
  {1,  (char *)"C#"},
  {2,  (char *)"D"},
  {3,  (char *)"D#"},
  {4,  (char *)"E"},
  {5,  (char *)"F"},
  {6,  (char *)"F#"},
  {7,  (char *)"G"},
  {8,  (char *)"G#"},
  {9,  (char *)"A"},
  {10, (char *)"A#"},
  {11, (char *)"B"},
};

RavenMenuOption musicScaleOptions[NUM_MUSIC_SCALES] = {
  {0,  (char *)"CHROMATIC"},                // 0  chromatic
  {1,  (char *)"AEOLIAN"},                  // 1  aeolian
  {2,  (char *)"MAJ BLUES"},                // 2  major blues
  {3,  (char *)"MIN BLUES"},                // 3  minor blues
  {4,  (char *)"DORIAN"},                   // 4  dorian
  {5,  (char *)"EGYPTIAN"},                 // 5  egyptian
  {6,  (char *)"ENGMTIC"},                  // 6  enigmatic
  {7,  (char *)"FLAMENCO"},                 // 7  flamenco
  {8,  (char *)"HARM MAJ"},                 // 8  harmonic major
  {9,  (char *)"HARM MIN"},                 // 9  harmonic minor
  {10, (char *)"HUNG MAJ"},                 // 10 hungarian major
  {11, (char *)"HUNG MIN"},                 // 11 hungarian minor
  {12, (char *)"HEXA MIN"},                 // 12 minor hexatonic
  {13, (char *)"ION PENTA"},                // 13 ionian pentatonic
  {14, (char *)"MELOD MIN"},                // 14 melodic minor
  {15, (char *)"MAJ PENTA"},                // 15 major pentatonic
  {16, (char *)"MIN PENTA"},                // 16 minor pentatonic
  {17, (char *)"MIN 6PENT"},                // 17 minor six pentatonic
  {18, (char *)"LOC MAJ"},                  // 18 locrian major
  {19, (char *)"LOC PENTA"},                // 19 locrian pentatonic
  {20, (char *)"LOC SUPER"},                // 20 super locrian pentatonic
  {21, (char *)"LOC ULTRA"},                // 21 ultralocrian
  {22, (char *)"LYD MIN"},                  // 22 lydian minor
  {23, (char *)"LYD PENTA"},                // 23 lydian pentatonic
  {24, (char *)"2XHARMLYD"},                // 24 double harmonic lydian
  {25, (char *)"2XHARMMAJ"},                // 25 double harmonic major
  {26, (char *)"MIXOLYDIA"},                // 26 mixolydian
  {27, (char *)"MIXOPENTA"},                // 27 mixolydian pentatonic
  {28, (char *)"NEOMAJ"},                   // 28 neopolitan major
  {29, (char *)"NEOMAJPENT"},               // 29 neopolitan major pentatonic
  {30, (char *)"ORIENTAL"},                 // 30 oriental
  {31, (char *)"MALKOSRAGA"},               // 31 malkos raga
  {32, (char *)"PERSIAN"},                  // 32 persian
  {33, (char *)"PHRYGIAN"},                 // 33 phrygian
  {34, (char *)"PIONGIO"},                  // 34 piongio
  {35, (char *)"PROMETHEUS"},               // 35 prometheus
  {36, (char *)"RITUSEN"},                  // 36 ritusen
  {37, (char *)"SCRIABIN"},                 // 37 scriabin
  {38, (char *)"WHOLETONE"},                // 38 whole tone
  {39, (char *)"WHOLEPENTA"}                // 39 whole tone pentatonic
};

const int musicScaleIntervals[NUM_MUSIC_SCALES][NUM_SCALE_INTERVALS] = {
  {1,2,3,4,5,6,7,8,9,10,11,12},             // 0  chromatic
  {2,3,5,7,8,10,12,14,15,17,19,20},         // 1  aeolian
  {2,3,4,7,9,12,14,15,16,19,21,24},         // 2  major blues
  {3,5,6,7,10,12,15,17,18,19,22,24},        // 3  minor blues
  {2,3,5,7,9,10,12,14,15,17,19,21},         // 4  dorian
  {2,5,7,10,12,14,17,19,22,24,26,29},       // 5  egyptian
  {1,4,6,8,10,11,12,13,16,18,20,22},        // 6  enigmatic
  {1,3,4,6,7,10,12,13,15,16,18,19},         // 7  flamenco
  {2,4,5,7,8,11,12,14,16,17,19,20},         // 8  harmonic major
  {2,3,5,7,8,11,12,14,15,17,19,20},         // 9  harmonic minor
  {3,4,6,7,9,10,12,15,16,18,19,21},         // 10 hungarian major
  {2,3,6,7,8,11,12,14,15,18,19,20},         // 11 hungarian minor
  {2,3,5,7,11,12,14,15,17,19,23,24},        // 12 minor hexatonic
  {4,5,7,11,12,16,17,19,23,24,28,29},       // 13 ionian pentatonic
  {2,3,5,7,9,11,12,14,15,17,19,21},         // 14 melodic minor
  {2,4,7,9,12,14,16,19,21,24,26,28},        // 15 major pentatonic
  {3,5,7,10,12,15,17,19,22,24,27,29},       // 16 minor pentatonic
  {3,5,7,9,12,15,17,19,21,24,27,29},        // 17 minor six pentatonic
  {2,4,5,6,8,10,12,14,16,17,18,20},         // 18 locrian major
  {3,5,6,10,12,15,17,18,22,24,27,29},       // 19 locrian pentatonic
  {3,4,6,10,12,15,16,18,22,24,27,28},       // 20 super locrian pentatonic
  {1,3,4,6,8,9,12,13,15,16,18,20},          // 21 ultralocrian
  {2,4,6,7,8,10,12,14,16,18,19,20},         // 22 lydian minor
  {4,6,7,11,12,16,18,19,23,24,28,30},       // 23 lydian pentatonic
  {1,4,6,7,8,11,12,13,16,18,19,20},         // 24 double harmonic lydian
  {1,4,5,7,8,11,12,13,16,17,19,20},         // 25 double harmonic major
  {2,4,5,7,9,10,12,14,16,17,19,21},         // 26 mixolydian
  {4,5,7,10,12,16,17,19,22,24,28,29},       // 27 mixolydian pentatonic
  {1,3,5,7,9,11,12,13,15,17,19,21},         // 28 neopolitan major
  {4,5,6,10,12,16,17,18,22,24,28,29},       // 29 neopolitan major pentatonic
  {1,4,5,6,9,10,12,13,16,17,18,21},         // 30 oriental
  {3,5,8,10,12,15,17,20,22,24,27,29},       // 31 malkos raga
  {1,4,5,6,8,11,12,13,16,17,18,20},         // 32 persian
  {1,3,5,7,8,10,12,13,15,17,19,20},         // 33 phrygian
  {2,5,7,9,10,12,14,17,19,21,22,24},        // 34 piongio
  {2,4,6,9,10,12,14,16,18,21,22,24},        // 35 prometheus
  {2,5,7,9,12,14,17,19,21,24,26,29},        // 36 ritusen
  {1,4,7,9,12,13,16,19,21,24,25,28},        // 37 scriabin
  {2,4,6,8,10,12,14,16,18,20,22,24},        // 38 whole tone
  {4,6,8,10,12,16,18,20,22,24,28,30}        // 39 whole tone pentatonic
};

RavenMenuOption musicKeyOptions[NUM_MUSIC_KEYS] = {
  {0,  (char *)"A"},
  {1,  (char *)"Am"},
  {2,  (char *)"Ab"},
  {3,  (char *)"A#"},
  {4,  (char *)"Abm"},
  {5,  (char *)"B"},
  {6,  (char *)"Bm"},
  {7,  (char *)"Bbm"},
  {8,  (char *)"C"},
  {9,  (char *)"Cm"},
  {10, (char *)"C#"},
  {11, (char *)"C#m"},
  {12, (char *)"D"},
  {13, (char *)"Dm"},
  {14, (char *)"D#m"},
  {15, (char *)"Db"},
  {16, (char *)"E"},
  {17, (char *)"Em"},
  {18, (char *)"Eb"},
  {19, (char *)"F"},
  {20, (char *)"F#"},
  {21, (char *)"Fm"},
  {22, (char *)"F#m"},
  {23, (char *)"G"},
  {24, (char *)"Gm"},
  {25, (char *)"G#m"}
};

const int musicKeyChords[NUM_MUSIC_KEYS][NUM_MUSIC_KEY_CHORDS] = {
  {0,12,23,32,43,55,68},   // 0   A     (A,Bm,C#m,D,E,F#m,G#dim)
  {1,16,20,33,44,52,62},   // 1   Am    (Am,Bdim,C,Dm,Em,F,G)
  {2,14,21,37,46,53,69},   // 2   Ab    (Ab,Bbm,Cm,Db,Eb,Fm,Gdim)
  {13,21,33,46,52,63,6},   // 3   A#    (Bb,Cm,Dm,Eb,F,Gm,Adim)
  {3,15,31,38,47,61,64},   // 4   Abm   (Abm,Bbdim,Cb,Dbm,Ebm,Fb,Gb)
  {11,23,35,43,54,67,7},   // 5   B     (B,C#m,D#m,E,F#,G#m,A#dim)
  {12,24,32,44,55,62,0},   // 6   Bm    (Bm,C#dim,D,Em,F#m,G,A)
  {14,25,37,47,53,64,2},   // 7   Bbm   (Bbm,Cdim,Db,Ebm,Fm,Gb,Ab)
  {20,33,44,52,62,1,16},   // 8   C     (C,Dm,Em,F,G,Am,Bdim)
  {21,39,46,53,63,2,13},   // 9   Cm    (Cm,Ddim,Eb,Fm,Gm,Ab,Bb)
  {22,35,53,54,66,5,25},   // 10  C#    (C#,D#m,Fm,F#,G#,A#m,Cdim)
  {23,36,43,55,67,0,11},   // 11  C#m   (C#m,D#dim,E,F#m,G#m,A,B)
  {32,44,55,62,0,12,24},   // 12  D     (D,Em,F#m,G,A,Bm,C#dim)
  {33,48,52,63,1,13,20},   // 13  Dm    (Dm,Edim,F,Gm,Am,Bb,C)
  {35,57,54,67,5,11,22},   // 14  D#m   (D#m,Fdim,F#,G#m,A#m,B,C#)
  {37,47,53,64,2,14,25},   // 15  Db    (Db,Ebm,Fm,Gb,Ab,Bbm,Cdim)
  {43,55,67,0,11,23,36},   // 16  E     (E,F#m,G#m,A,B,C#m,D#dim)
  {44,56,62,1,12,20,32},   // 17  Em    (Em,F#dim,G,Am,Bm,C,D)
  {46,53,63,2,13,21,33},   // 18  Eb    (Eb,Fm,Gm,Ab,Bb,Cm,Dm)
  {52,63,1,13,20,33,48},   // 19  F     (F,Gm,Am,Bb,C,Dm,Edim)
  {54,67,5,11,22,35,57},   // 20  F#    (F#,G#m,A#m,B,C#,D#m,Fdim)
  {53,69,2,14,21,37,46},   // 21  Fm    (Fm,Gdim,Ab,Bbm,Cm,Db,Eb)
  {55,68,0,12,23,32,43},   // 22  F#m   (F#m,G#dim,A,Bm,C#m,D,E)
  {62,1,12,20,32,44,56},   // 23  G     (G,Am,Bm,C,D,Em,F#dim)
  {63,6,13,21,33,46,52},   // 24  Gm    (Gm,Adim,Bb,Cm,Dm,Eb,F)
  {67,7,11,23,35,43,54}    // 25  G#m   (G#m,A#dim,B,C#m,D#m,E,F#)
};

const char* chordNames[NUM_MUSIC_CHORDS][] = {
  "A",     // 0
  "Am",    // 1
  "Ab",    // 2
  "Abm",   // 3
  "A#",    // 4
  "A#m",   // 5
  "Adim",  // 6
  "A#dim", // 7
  "Asus2", // 8
  "Asus4", // 9
  "A7",    // 10
  "B",     // 11
  "Bm",    // 12
  "Bb",    // 13
  "Bbm",   // 14
  "Bbdim", // 15
  "Bdim",  // 16
  "Bsus2", // 17
  "Bsus4", // 18
  "B7",    // 19
  "C",     // 20
  "Cm",    // 21
  "C#",    // 22
  "C#m",   // 23
  "C#dim", // 24
  "Cdim",  // 25
  "C9",    // 26
  "Cadd9", // 27
  "Csus2", // 28
  "Csus4", // 29
  "C7",    // 30
  "Cb",    // 31
  "D",     // 32
  "Dm",    // 33
  "D#",    // 34
  "D#m",   // 35
  "D#dim", // 36
  "Db",    // 37
  "Dbm",   // 38
  "Ddim",  // 39
  "Dsus2", // 40
  "Dsus4", // 41
  "D7",    // 42
  "E",     // 43
  "Em",    // 44
  "E#dim", // 45
  "Eb",    // 46
  "Ebm",   // 47
  "Edim",  // 48
  "Esus2", // 49
  "Esus4", // 50
  "E7",    // 51
  "F",     // 52
  "Fm",    // 53
  "F#",    // 54
  "F#m",   // 55
  "F#dim", // 56
  "Fdim",  // 57
  "Fsus2", // 58
  "Fsus4", // 59
  "F7",    // 60
  "Fb",    // 61
  "G",     // 62
  "Gm",    // 63
  "Gb",    // 64
  "Gbm",   // 65
  "G#",    // 66
  "G#m",   // 67
  "G#dim", // 68
  "Gdim",  // 69
  "Gsus2", // 70
  "Gsus4", // 71
  "G7"     // 72
};

/*
const int chordChromaValues[NUM_MUSIC_CHORDS][NUM_CHORD_NOTES] = {
  {9,1,4},       // 0  A
  {9,0,4},       // 1  Am
  {8,0,3},       // 2  Ab
  {8,11,3},      // 3  Abm
  {10,2,5},      // 4  A#
  {10,1,5},      // 5  A#m
  {9,0,3},       // 6  Adim
  {10,1,4},      // 7  A#dim
  {9,11,4},      // 8  Asus2
  {9,2,4},       // 9  Asus4
  {9,1,4,7},     // 10 A7
  {11,3,6},      // 11 B
  {11,2,6},      // 12 Bm
  {10,2,5},      // 13 Bb
  {10,1,5},      // 14 Bbm
  {10,1,4},      // 15 Bbdim
  {11,2,5},      // 16 Bdim
  {11,1,6},      // 17 Bsus2
  {11,4,6},      // 18 Bsus4
  {11,3,6,9},    // 19 B7
  {0,4,7},       // 20 C
  {0,3,7},       // 21 Cm
  {1,5,8},       // 22 C#
  {1,4,8},       // 23 C#m
  {1,4,7},       // 24 C#dim
  {0,3,6},       // 25 Cdim
  {0,4,7,10,2},  // 26 C9
  {0,4,7,2},     // 27 Cadd9
  {0,2,7},       // 28 Csus2
  {0,5,7},       // 29 Csus4
  {0,4,7,10},    // 30 C7
  {11,3,6},      // 31 Cb
  {2,6,9},       // 32 D
  {2,5,9},       // 33 Dm
  {3,7,10},      // 34 D#
  {3,6,10},      // 35 D#m
  {3,6,9},       // 36 D#dim
  {1,5,8},       // 37 Db
  {1,4,8},       // 38 Dbm
  {2,5,8},       // 39 Ddim
  {2,4,9},       // 40 Dsus2
  {2,7,9},       // 41 Dsus4
  {2,6,9,0},     // 42 D7
  {4,8,11},      // 43 E
  {4,7,11},      // 44 Em
  {5,8,11},      // 45 E#dim
  {3,7,10},      // 46 Eb
  {3,6,10},      // 47 Ebm
  {4,7,10},      // 48 Edim
  {4,6,11},      // 49 Esus2
  {4,9,11},      // 50 Esus4
  {4,8,11,2},    // 51 E7
  {5,9,0},       // 52 F
  {5,8,0},       // 53 Fm
  {6,10,1},      // 54 F#
  {6,9,1},       // 55 F#m
  {6,9,0},       // 56 F#dim
  {5,8,11},      // 57 Fdim
  {5,7,0},       // 58 Fsus2
  {5,10,0},      // 59 Fsus4
  {5,9,0,3},     // 60 F7
  {4,8,11},      // 61 Fb
  {7,11,2},      // 62 G
  {7,10,2},      // 63 Gm
  {6,10,1},      // 64 Gb
  {6,9,1},       // 65 Gbm
  {8,0,3},       // 66 G#
  {8,11,3},      // 67 G#m
  {8,11,2},      // 68 G#dim
  {7,10,1},      // 69 Gdim
  {7,9,2},       // 70 Gsus2
  {7,0,2},       // 71 Gsus4
  {7,11,2,5},    // 72 G7
};
*/

const int chordStringMidiNotes[NUM_MUSIC_CHORDS][NUM_CHORD_NOTES] = {
  {4,9,16,21,25,28},   // 0   A        (E-1,A-1,E0,A0,C#1,E1)
  {4,9,16,21,24,28},   // 1   Am       (E-1,A-1,E0,A0,C1,E1)
  {8,15,20,24,27,32},  // 2   Ab       (G#-1,D#0,G#0,C1,D#1,G#1)
  {8,15,20,23,27,32},  // 3   Abm      (G#-1,D#0,G#0,B0,D#1,G#1)
  {5,10,14,22,26,29},  // 4   A#       (F-1,A#-1,D0,A#0,D1,F1)
  {5,10,17,22,25,29},  // 5   A#m      (F-1,A#-1,F0,A#0,C#1,F1)
  {9,15,21,24,27,33},  // 6   Adim     (A-1,D#0,A0,C1,D#1,A1)
  {4,10,16,22,25,28},  // 7   A#dim    (E-1,A#-1,E0,A#0,C#1,E1)
  {4,9,16,21,23,28},   // 8   Asus2    (E-1,A-1,E0,A0,B0,E1)
  {4,9,14,21,26,28},   // 9   Asus4    (E-1,A-1,D0,A0,D1,E1)
  {4,9,16,19,25,28},   // 10  A7       (E-1,A-1,E0,G0,C#1,E1)
  {6,11,15,23,27,30},  // 11  B        (F#-1,B-1,D#0,B0,D#1,F#1)
  {6,11,14,23,26,30},  // 12  Bm       (F#-1,B-1,D0,B0,D1,F#1)
  {5,10,14,22,26,29},  // 13  Bb       (F-1,A#-1,D0,A#0,D1,F1)
  {5,10,17,22,25,29},  // 14  Bbm      (F-1,A#-1,F0,A#0,C#1,F1)
  {4,10,16,22,25,28},  // 15  Bbdim    (E-1,A#-1,E0,A#0,C#1,E1)
  {5,11,14,23,26,29},  // 16  Bdim     (F-1,B-1,D0,B0,D1,F1)
  {6,11,18,23,25,30},  // 17  Bsus2    (F#-1,B-1,F#0,B0,C#1,F#1)
  {4,11,16,23,28,30},  // 18  Bsus4    (E-1,B-1,E0,B0,E1,F#1)
  {6,11,15,21,23,30},  // 19  B7       (F#-1,B-1,D#0,A0,B0,F#1)
  {4,12,16,19,24,28},  // 20  C        (E-1,C0,E0,G0,C1,E1)
  {7,12,15,19,24,31},  // 21  Cm       (G-1,C0,D#0,G0,C1,G1)
  {5,13,17,20,25,29},  // 22  C#       (F-1,C#0,F0,G#0,C#1,F1)
  {4,13,16,20,25,28},  // 23  C#m      (E-1,C#0,E0,G#0,C#1,E1)
  {4,13,16,19,25,28},  // 24  C#dim    (E-1,C#0,E0,G0,C#1,E1)
  {6,12,15,24,27,30},  // 25  Cdim     (F#-1,C0,D#0,C1,D#1,F#1)
  {4,10,14,19,24,28},  // 26  C9       (E-1,A#-1,D0,G0,C1,E1)
  {4,12,14,19,24,28},  // 27  Cadd9    (E-1,C0,D0,G0,C1,E1)
  {7,12,14,19,24,31},  // 28  Csus2    (G-1,C0,D0,G0,C1,G1)
  {5,12,17,19,24,29},  // 29  Csus4    (F-1,C0,F0,G0,C1,F1)
  {4,10,16,19,24,28},  // 30  C7       (E-1,A#-1,E0,G0,C1,E1)
  {6,11,15,23,27,30},  // 31  Cb       (F#-1,B-1,D#0,B0,D#1,F#1)
  {6,14,18,21,26,30},  // 32  D        (F#-1,D0,F#0,A0,D1,F#1)
  {5,14,17,21,26,29},  // 33  Dm       (F-1,D0,F0,A0,D1,F1)
  {7,15,19,22,27,31},  // 34  D#       (G-1,D#0,G0,A#0,D#1,G1)
  {6,15,18,22,27,30},  // 35  D#m      (F#-1,D#0,F#0,A#0,D#1,F#1)
  {6,15,18,21,27,30},  // 36  D#dim    (F#-1,D#0,F#0,A0,D#1,F#1)
  {5,13,17,20,25,29},  // 37  Db       (F-1,C#0,F0,G#0,C#1,F1)
  {4,13,16,20,25,28},  // 38  Dbm      (E-1,C#0,E0,G#0,C#1,E1)
  {5,14,17,20,26,29},  // 39  Ddim     (F-1,D0,F0,G#0,D1,F1)
  {4,9,14,21,26,28},   // 40  Dsus2    (E-1,A-1,D0,A0,D1,E1)
  {7,14,19,21,26,31},  // 41  Dsus4    (G-1,D0,G0,A0,D1,G1)
  {6,12,14,21,24,30},  // 42  D7       (F#-1,C0,D0,A0,C1,F#1)
  {4,11,16,20,23,28},  // 43  E        (E-1,B-1,E0,G#0,B0,E1)
  {4,11,16,19,23,28},  // 44  Em       (E-1,B-1,E0,G0,B0,E1)
  {5,11,17,20,23,29},  // 45  E#dim    (F-1,B-1,F0,G#0,B0,F1)
  {7,15,19,22,27,31},  // 46  Eb       (G-1,D#0,G0,A#0,D#1,G1)
  {6,15,18,22,27,30},  // 47  Ebm      (F#-1,D#0,F#0,A#0,D#1,F#1)
  {4,10,16,19,28,31},  // 48  Edim     (E-1,A#-1,E0,G0,E1,G1)
  {4,11,16,23,28,30},  // 49  Esus2    (E-1,B-1,E0,B0,E1,F#1)
  {4,9,16,21,23,28},   // 50  Esus4    (E-1,A-1,E0,A0,B0,E1)
  {4,11,14,20,23,28},  // 51  E7       (E-1,B-1,D0,G#0,B0,E1)
  {5,12,17,21,24,29},  // 52  F        (F-1,C0,F0,A0,C1,F1)
  {5,12,17,20,24,29},  // 53  Fm       (F-1,C0,F0,G#0,C1,F1)
  {6,13,18,22,25,30},  // 54  F#       (F#-1,C#0,F#0,A#0,C#1,F#1)
  {6,13,18,21,25,30},  // 55  F#m      (F#-1,C#0,F#0,A0,C#1,F#1)
  {6,12,18,21,24,30},  // 56  F#dim    (F#-1,C0,F#0,A0,C1,F#1)
  {5,11,17,20,23,29},  // 57  Fdim     (F-1,B-1,F0,G#0,B0,F1)
  {5,12,17,19,24,29},  // 58  Fsus2    (F-1,C0,F0,G0,C1,F1)
  {5,10,17,22,24,29},  // 59  Fsus4    (F-1,A#-1,F0,A#0,C1,F1)
  {5,12,15,21,24,29},  // 60  F7       (F-1,C0,D#0,A0,C1,F1)
  {4,11,16,20,23,28},  // 61  Fb       (E-1,B-1,E0,G#0,B0,E1)
  {7,14,19,23,26,31},  // 62  G        (G-1,D0,G0,B0,D1,G1)
  {7,14,19,22,26,31},  // 63  Gm       (G-1,D0,G0,A#0,D1,G1)
  {6,13,18,22,25,30},  // 64  Gb       (F#-1,C#0,F#0,A#0,C#1,F#1)
  {6,13,18,21,25,30},  // 65  Gbm      (F#-1,C#0,F#0,A0,C#1,F#1)
  {8,15,20,24,27,32},  // 66  G#       (G#-1,D#0,G#0,C1,D#1,G#1)
  {8,15,20,23,27,32},  // 67  G#m      (G#-1,D#0,G#0,B0,D#1,G#1)
  {8,14,20,23,26,32},  // 68  G#dim    (G#-1,D0,G#0,B0,D1,G#1)
  {7,13,19,22,25,31},  // 69  Gdim     (G-1,C#0,G0,A#0,C#1,G1)
  {7,14,19,21,26,31},  // 70  Gsus2    (G-1,D0,G0,A0,D1,G1)
  {7,12,14,19,24,31},  // 71  Gsus4    (G-1,C0,D0,G0,C1,G1)
  {5,11,14,19,23,29}   // 72  G7       (F-1,B-1,D0,G0,B0,F1)
};