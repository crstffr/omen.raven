let { keys } = require('guitar-chord-definitions/dist/keys');
let { chords } = require('guitar-chord-definitions/dist/chords');

const {
  Chord,
  ChordType,
  Key,
  Note,
  Progression,
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

for (let i in keys) {
  const key = keys[i];
  if (key.chords) {
    for (let ii in key.chords) {
      key.chords[ii] = key.chords[ii].replace('E#', 'F').replace('B#', 'C');
    }
  }
}

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

generateMidiNotesForChords();

