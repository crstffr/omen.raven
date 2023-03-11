let { keys } = require('guitar-chord-definitions/dist/keys');
let { chords } = require('guitar-chord-definitions/dist/chords');

const {
  Chord,
  ChordType,
  distance,
  Interval,
  Key,
  Note,
  Progression,
  Scale,
  Range
} = require('@tonaljs/tonal');

const romanNums = [
  'I',  'i',
  'II', 'ii',
  'III','iii',
  'IV', 'iv',
  'V',  'v',
  'VI', 'vi',
  'VII','vii',
];

const scales = [
  ['chromatic',                         'CHROMATIC'],
  ['aeolian',                           'AEOLIAN'],
  ['major blues',                       'MAJ BLUES'],
  ['minor blues',                       'MIN BLUES'],
  ['dorian',                            'DORIAN'],
  ['egyptian',                          'EGYPTIAN'],
  ['enigmatic',                         'ENIGMATIC'],
  ['flamenco',                          'FLAMENCO'],
  ['harmonic major',                    'HARM MAJ'],
  ['harmonic minor',                    'HARM MIN'],
  ['hungarian major',                   'HUNG MAJ'],
  ['hungarian minor',                   'HUNG MIN'],
  ['minor hexatonic',                   'HEXA MIN'],
  ['ionian pentatonic',                 'ION PENTA'],
  ['melodic minor',                     'MELOD MIN'],
  ['major pentatonic',                  'MAJ PENTA'],
  ['minor pentatonic',                  'MIN PENTA'],
  ['minor six pentatonic',              'MIN 6 PENT'],
  ['locrian major',                     'LOC MAJ'],
  ['locrian pentatonic',                'LOC PENTA'],
  ['super locrian pentatonic',          'LOC SUPER'],
  ['ultralocrian',                      'LOC ULTRA'],
  ['lydian minor',                      'LYD MIN'],
  ['lydian pentatonic',                 'LYD PENTA'],
  ['double harmonic lydian',            '2X HARMLYD'],
  ['double harmonic major',             '2X HARMMAJ'],
  ['mixolydian',                        'MIXOLYDIA'],
  ['mixolydian pentatonic',             'MIXO PENTA'],
  ['neopolitan major',                  'NEOMAJ'],
  ['neopolitan major pentatonic',       'NEOMAJPENT'],
  ['oriental',                          'ORIENTAL'],
  ['malkos raga',                       'MALKOSRAGA'],
  ['persian',                           'PERSIAN'],
  ['phrygian',                          'PHRYGIAN'],
  ['piongio',                           'PIONGIO'],
  ['prometheus',                        'PROMETHEUS'],
  ['ritusen',                           'RITUSEN'],
  ['scriabin',                          'SCRIABIN'],
  ['whole tone',                        'WHOLETONE'],
  ['whole tone pentatonic',             'WHOLEPENTA'],
];

const tuningOctaves = [-1, -1, 0, 0, 0, 1];

const tunings = {
  'STANDARD':     ['E', 'A', 'D', 'G', 'B', 'E'],
  'DROP D':       ['D', 'A', 'D', 'G', 'B', 'E'],
  'DROP Db':      ['Db','Ab','Db','Gb','Bb','Eb'],
  'DBL DROP D':   ['D', 'A', 'D', 'G', 'B', 'D'],
  'DADGAD':       ['D', 'A', 'D', 'G', 'A', 'D'],
  'OPEN A':       ['E', 'A', 'C#','E', 'A', 'E'],
  'OPEN B':       ['B', 'F#','B', 'F#','B', 'D#'],
  'OPEN C':       ['C', 'G', 'C', 'G', 'C', 'E'],
  'OPEN D':       ['D', 'A', 'D', 'F#','A', 'D'],
  'OPEN E':       ['E', 'B', 'E', 'G#','B', 'E'],
  'OPEN F':       ['C', 'F', 'C', 'F', 'A', 'F'],
  'OPEN G':       ['D', 'G', 'D', 'G', 'B', 'D'],
}

// ******************************************************

for (let i in keys) {
  const key = keys[i];
  if (key.chords) {
    for (let ii in key.chords) {
      key.chords[ii] = key.chords[ii].replace('E#', 'F').replace('B#', 'C');
    }
  }
}

// ******************************************************

// generateNoteNamesArray();
// generateNoteNamesOptions();
// generateScaleNamesArray();
// generateScaleIntervals();
generateGuitarTuningOptions();

// ******************************************************
// ******************************************************
// ******************************************************

/** @return {Chord[]} */
function getChords() {
  return chords.map(c => Chord.get(c.shortName)).filter(c => !c.empty)
}

function getChordsMap() {
  return getChords().reduce((map, c, i) => {
    map[c.symbol] = i;
    return map;
  }, {})
}

/** @type {Record<string,string[]>} */
function getChordNotes() {
  return getChords().reduce((map, c) => {
    map[c.symbol] = c.intervals.map(Note.transposeFrom(c.tonic))
    return map;
  }, {});
}

function getChordChromas() {
  const chordChromas = {};
  const chordNotes = getChordNotes();
  for (let chord in chordNotes) {
    const notes = chordNotes[chord];
    chordChromas[chord] = notes.map(Note.chroma);
  }
  return chordChromas;
}


function getKeys() {
  return keys.filter(key => !key.copyFrom);
}

function getKeyChords() {
  return getKeys().reduce((map, key) => {
    map[key.shortName] = Object.values(key.chords);
    return map;
  }, {});
}

// ******************************************************

function generateNoteNamesArray() {
  console.log();
  console.log(`#define NUM_MUSIC_NOTES 12`);
  console.log();
  console.log(`const char* noteNames[NUM_MUSIC_NOTES][] = {`);
  Array(12).fill(0).forEach((_, i) => {
    const note = Note.get(Note.fromMidiSharps(i)).pc;
    console.log(`  (char *)"${note}",`.padEnd(22), `// ${i}`);
  });
  console.log(`};`);
}

function generateNoteNamesOptions() {
  console.log();
  console.log(`#define NUM_MUSIC_NOTES 12`);
  console.log();
  console.log(`RavenMenuOption scaleNoteOptions[NUM_MUSIC_NOTES] = {`);
  Array(12).fill(0).forEach((_, i) => {
    const note = Note.get(Note.fromMidiSharps(i)).pc;
    console.log(`  {${i},`.padEnd(6), `(char *)"${note}"},`);
  });
  console.log(`};`);
}


function generateScaleNamesArray() {
  console.log();
  console.log(`#define NUM_MUSIC_SCALES ${scales.length}`);
  console.log();
  console.log(`RavenMenuOption musicScaleOptions[NUM_MUSIC_SCALES] = {`);
  scales.forEach(([id, name], i) => {
    console.log(`  {${i},`.padEnd(6), `(char *)"${name}"},`.padEnd(35), ` // ${i}`.padEnd(6), `${id}`);
  });
  console.log(`};`);
}

// ******************************************************

function generateScaleIntervals() {

  const numints = 11; // 12 minus the root

  console.log();
  console.log(`#define NUM_MUSIC_SCALES ${scales.length}`);
  console.log(`#define NUM_SCALE_INTERVALS ${numints}`);
  console.log();
  console.log(`const int SCALE_INTERVALS[NUM_MUSIC_SCALES][NUM_SCALE_INTERVALS] = {`);
  scales.forEach(([id, name], i) => {

    const note = Note.fromMidiSharps(0);
    const base = Note.get(note).pc;
    const range = Scale.rangeOf(`${note} ${id}`)(`${note}`, `${base}2`);

    const set = range.map(Note.simplify).slice(1,numints+1).map(n => {
      const dist = distance(note, n);
      return Interval.semitones(dist);
    });

    console.log(`  {${set.join(',')}},`.padEnd(42), ` // ${i}`.padEnd(6), `${id}`);
  });
  console.log(`};`);
}

// ******************************************************

function generateGuitarTuningOptions() {

  console.log();
  console.log(`#define NUM_GUITAR_TUNINGS ${Object.keys(tunings).length}`);

  console.log(`{`);
  Object.keys(tunings).forEach((val, i) => {
    console.log(`  {${i},`.padEnd(6), `(char *)"${val}"},`);
  });
  console.log(`};`);

  console.log();
  console.log(`const int GUITAR_TUNINGS[NUM_GUITAR_TUNINGS][NUM_STRUM_PDLS] = {`);
  Object.entries(tunings).forEach(([tuning, notes], i) => {
    const midis = notes.map((n,i) => Note.get(`${n}${tuningOctaves[i]}`).midi);
    console.log(`  {${midis}},`.padEnd(25), ` // ${i}`.padEnd(7), `(${notes})`);
  });
  console.log(`};`);

}

// ******************************************************

function generateMusicKeyOptions() {
  console.log(`{`);
  getKeys().forEach((key, i) => {
    console.log(`  {${i},`.padEnd(6), `(char *)"${key.shortName}"},`);
  });
  console.log(`};`);
}

// generateMusicKeyOptions();

// ******************************************************

function generateMusicKeyChordsArray() {
  console.log(`{`);
  const chordsMap = getChordsMap();
  Object.entries(getKeyChords()).forEach(([chord, chords], i) => {
    const mappedChords = chords.map(c => chordsMap[c]);
    console.log(`  {${mappedChords}},`.padEnd(25), ` // ${i}`.padEnd(7), `${chord}`.padEnd(5), `(${chords})`);
  });
  console.log(`};`);
}

// generateMusicKeyChordsArray();

// ******************************************************

function generateChordNamesArray() {
  console.log(`{`);
  getChords().forEach((chord, i) => {
    console.log(`  "${chord.symbol}",`.padEnd(10), `// ${i}`);
  });
  console.log(`};`);
}

// generateChordNamesArray();

// ******************************************************

function generateChordChromaValuesArray() {
  console.log(`{`);
  Object.entries(getChordChromas()).forEach(([chord, chromas], i) => {
    console.log(`  {${chromas}},`.padEnd(15), ` // ${i}`.padEnd(6), `${chord}`);
  });
  console.log(`};`);
}

// generateChordChromaValuesArray();

// ******************************************************

function generateMidiNotesForChords() {
  console.log(`{`);

  const tuning = ['E-1', 'A-1', 'D0', 'G0', 'B0', 'E1'];
  // const tuning = ['E2', 'A2', 'D3', 'G3', 'B3', 'E4'];

  const strings = tuning.map(root => {
    const val = Note.get(root).midi;
    return Range.numeric([val, val + 8]).map(Note.fromMidiSharps);
  });

  Object.entries(getChordChromas()).forEach(([chord, chromas], i) => {

    const chordValues = [];

    strings.forEach((stringNotes, i) => {

      let found = false;
      const lastNote = chordValues[chordValues.length - 1];

      stringNotes.forEach(noteName => {

        const note = Note.get(noteName);
        if (found || note.empty) return;
        const midi = note.midi;

        // This ensures the notes get higher as we go
        if (chordValues.length && midi <= lastNote) return;

        // This ensures the second note isn't too close to the first (sounds better!)
        if (chordValues.length === 1 && midi < lastNote + 5) return;

        if (chromas.includes(note.chroma)) {
          chordValues.push(note.midi);
          found = true;
        }
      });
    });

    const chordNotes = chordValues.map(Note.fromMidiSharps);
    console.log(`  {${chordValues}},`.padEnd(22), `// ${i}`.padEnd(6), `${chord}`.padEnd(8), `(${chordNotes})`);
  });

  console.log(`};`);
}

// generateMidiNotesForChords();

