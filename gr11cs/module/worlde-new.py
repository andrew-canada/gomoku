# Wordle
# A game where the user has 6 chances to guess a 5-letter word
# Author: Andrew Peng
import random
import os
WORDS = ["eease", "eeese", "aaaea", "eeeaa", "shepe", 'which', 'there', 'their', 'about', 'would', 'these', 'other', 'words', 'could', 'write', 'first', 'water', 'after', 'where', 'right', 'think', 'three', 'years', 'place', 'sound', 'great', 'again', 'still', 'every', 'small', 'found', 'those', 'never', 'under', 'might', 'while', 'house', 'world', 'below', 'asked', 'going', 'large', 'until', 'along', 'shall', 'being', 'often', 'earth', 'began', 'since', 'study', 'night', 'light', 'above', 'paper', 'parts', 'young', 'story', 'point', 'times', 'heard', 'whole', 'white', 'given', 'means', 'music', 'miles', 'thing', 'today', 'later', 'using', 'money', 'lines', 'order', 'group', 'among', 'learn', 'known', 'space', 'table', 'early', 'trees', 'short', 'hands', 'state', 'black', 'shown', 'stood', 'front', 'voice', 'kinds', 'makes', 'comes', 'close', 'power', 'lived', 'vowel', 'taken', 'built', 'heart', 'ready', 'quite', 'class', 'bring', 'round', 'horse', 'shows', 'piece', 'green', 'stand', 'birds', 'start', 'river', 'tried', 'least', 'field', 'whose', 'girls', 'leave', 'added', 'color', 'third', 'hours', 'moved', 'plant', 'doing', 'names', 'forms', 'heavy', 'ideas', 'cried', 'check', 'floor', 'begin', 'woman', 'alone', 'plane', 'spell', 'watch', 'carry', 'wrote', 'clear', 'named', 'books', 'child', 'glass', 'human', 'takes', 'party', 'build', 'seems', 'blood', 'sides', 'seven', 'mouth', 'solve', 'north', 'value', 'death', 'maybe', 'happy', 'tells', 'gives', 'looks', 'shape', 'lives', 'steps', 'areas', 'sense', 'speak', 'force', 'ocean', 'speed', 'women', 'metal', 'south', 'grass', 'scale', 'cells', 'lower', 'sleep', 'wrong', 'pages', 'ships', 'needs', 'rocks', 'eight', 'major', 'level', 'total', 'ahead', 'reach', 'stars', 'store', 'sight', 'terms', 'catch', 'works', 'board', 'cover', 'songs', 'equal', 'stone', 'waves', 'guess', 'dance', 'spoke', 'break', 'cause', 'radio', 'weeks', 'lands', 'basic', 'liked', 'trade', 'fresh', 'final', 'fight', 'meant', 'drive', 'spent', 'local', 'waxes', 'knows', 'train', 'bread', 'homes', 'teeth', 'coast', 'thick', 'brown', 'clean', 'quiet', 'sugar', 'facts', 'steel', 'forth', 'rules', 'notes', 'units', 'peace', 'month', 'verbs', 'seeds', 'helps', 'sharp', 'visit', 'woods', 'chief', 'walls', 'cross', 'wings', 'grown', 'cases', 'foods', 'crops', 'fruit', 'stick', 'wants', 'stage', 'sheep', 'nouns', 'plain', 'drink', 'bones', 'apart', 'turns', 'moves', 'touch', 'angle', 'based', 'range', 'marks', 'tired', 'older', 'farms', 'spend', 'shoes', 'goods', 'chair', 'twice', 'cents', 'empty', 'alike', 'style', 'broke', 'pairs', 'count', 'enjoy', 'score', 'shore', 'roots', 'paint', 'heads', 'shook', 'serve', 'angry', 'crowd', 'wheel', 'quick', 'dress', 'share', 'alive', 'noise', 'solid', 'cloth', 'signs', 'hills', 'types', 'drawn', 'worth', 'truck', 'piano', 'upper', 'loved', 'usual', 'faces', 'drove', 'cabin', 'boats', 'towns', 'proud', 'court', 'model', 'prime', 'fifty', 'plans', 'yards', 'prove', 'tools', 'price', 'sheet', 'smell', 'boxes', 'raise', 'match', 'truth', 'roads', 'threw', 'enemy', 'lunch', 'chart', 'scene', 'graph', 'doubt', 'guide', 'winds', 'block', 'grain', 'smoke', 'mixed', 'games', 'wagon', 'sweet', 'topic', 'extra', 'plate', 'title', 'knife', 'fence', 'falls', 'cloud', 'wheat', 'plays', 'enter', 'broad', 'steam', 'atoms', 'press', 'lying', 'basis', 'clock', 'taste', 'grows', 'thank', 'storm', 'agree', 'brain', 'track', 'smile', 'funny', 'beach', 'stock', 'hurry', 'saved', 'sorry', 'giant', 'trail', 'offer', 'ought', 'rough', 'daily', 'avoid', 'keeps', 'throw', 'allow', 'cream', 'laugh', 'edges', 'teach', 'frame', 'bells', 'dream', 'magic', 'occur', 'ended', 'chord', 'false', 'skill', 'holes', 'dozen', 'brave', 'apple', 'climb', 'outer', 'pitch', 'ruler', 'holds', 'fixed', 'costs', 'calls', 'blank', 'staff', 'labor', 'eaten', 'youth', 'tones', 'honor', 'globe', 'gases', 'doors', 'poles', 'loose', 'apply', 'tears', 'exact', 'brush', 'chest', 'layer', 'whale', 'minor', 'faith', 'tests', 'judge', 'items', 'worry', 'waste', 'hoped', 'strip', 'begun', 'aside', 'lakes', 'bound', 'depth', 'candy', 'event', 'worse', 'aware', 'shell', 'rooms', 'ranch', 'image', 'snake', 'aloud', 'dried', 'likes', 'motor', 'pound', 'knees', 'refer', 'fully', 'chain', 'shirt', 'flour', 'drops', 'spite', 'orbit', 'banks', 'shoot', 'curve', 'tribe', 'tight', 'blind', 'slept', 'shade', 'claim', 'flies', 'theme', 'queen', 'fifth', 'union', 'hence', 'straw', 'entry', 'issue', 'birth', 'feels', 'anger', 'brief', 'rhyme', 'glory', 'guard', 'flows', 'flesh', 'owned', 'trick', 'yours', 'sizes', 'noted', 'width', 'burst', 'route', 'lungs', 'uncle', 'bears', 'royal', 'kings', 'forty', 'trial', 'cards', 'brass', 'opera', 'chose', 'owner', 'vapor', 'beats', 'mouse', 'tough', 'wires', 'meter', 'tower', 'finds', 'inner', 'stuck', 'arrow', 'poems', 'label', 'swing', 'solar', 'truly', 'tense', 'beans', 'split', 'rises', 'weigh', 'hotel', 'stems', 'pride', 'swung', 'grade', 'digit', 'badly', 'boots', 'pilot', 'sales', 'swept', 'lucky', 'prize', 'stove', 'tubes', 'acres', 'wound', 'steep', 'slide', 'trunk', 'error', 'porch', 'slave', 'exist', 'faced', 'mines', 'marry', 'juice', 'raced', 'waved', 'goose', 'trust', 'fewer', 'favor', 'mills', 'views', 'joint', 'eager', 'spots', 'blend', 'rings', 'adult', 'index', 'nails', 'horns', 'balls', 'flame', 'rates', 'drill', 'trace', 'skins', 'waxed', 'seats', 'stuff', 'ratio', 'minds', 'dirty', 'silly', 'coins', 'hello', 'trips', 'leads', 'rifle', 'hopes', 'bases', 'shine', 'bench', 'moral', 'fires', 'meals', 'shake', 'shops', 'cycle', 'movie', 'slope', 'canoe', 'teams', 'folks', 'fired', 'bands', 'thumb', 'shout', 'canal', 'habit', 'reply', 'ruled', 'fever', 'crust', 'shelf', 'walks', 'midst', 'crack', 'print', 'tales', 'coach', 'stiff', 'flood', 'verse', 'awake', 'rocky', 'march', 'fault', 'swift', 'faint', 'civil', 'ghost', 'feast', 'blade', 'limit', 'germs', 'reads', 'ducks', 'dairy', 'worst', 'gifts', 'lists', 'stops', 'rapid', 'brick', 'claws', 'beads', 'beast', 'skirt', 'cakes', 'lions', 'frogs', 'tries', 'nerve', 'grand', 'armed', 'treat', 'honey', 'moist', 'legal', 'penny', 'crown', 'shock', 'taxes', 'sixty', 'altar', 'pulls', 'sport', 'drums', 'talks', 'dying', 'dates', 'drank', 'blows', 'lever', 'wages', 'proof', 'drugs', 'tanks', 'sings', 'tails', 'pause', 'herds', 'arose', 'hated', 'clues', 'novel', 'shame', 'burnt', 'races', 'flash', 'weary', 'heels', 'token', 'coats', 'spare', 'shiny', 'alarm', 'dimes', 'sixth', 'clerk', 'mercy', 'sunny', 'guest', 'float', 'shone', 'pipes', 'worms', 'bills', 'sweat', 'suits', 'smart', 'upset', 'rains', 'sandy', 'rainy', 'parks', 'sadly', 'fancy', 'rider', 'unity', 'bunch', 'rolls', 'crash', 'craft', 'newly', 'gates', 'hatch', 'paths', 'funds', 'wider', 'grace', 'grave', 'tides', 'admit', 'shift', 'sails', 'pupil', 'tiger', 'angel', 'cruel', 'agent', 'drama', 'urged', 'patch', 'nests', 'vital', 'sword', 'blame', 'weeds', 'screw', 'vocal', 'bacon', 'chalk', 'cargo', 'crazy', 'acted', 'goats', 'arise', 'witch', 'loves', 'queer', 'dwell', 'backs', 'ropes', 'shots', 'merry', 'phone', 'cheek', 'peaks', 'ideal', 'beard', 'eagle', 'creek', 'cries', 'ashes', 'stall', 'yield', 'mayor', 'opens', 'input', 'fleet', 'tooth', 'cubic', 'wives', 'burns', 'poets', 'apron', 'spear', 'organ', 'cliff', 'stamp', 'paste', 'rural', 'baked', 'chase', 'slice', 'slant', 'knock', 'noisy', 'sorts', 'stays', 'wiped', 'blown', 'piled', 'clubs', 'cheer', 'widow', 'twist', 'tenth', 'hides', 'comma', 'sweep', 'spoon', 'stern', 'crept', 'maple', 'deeds', 'rides', 'muddy', 'crime', 'jelly', 'ridge', 'drift', 'dusty', 'devil', 'tempo', 'humor', 'sends', 'steal', 'tents', 'waist', 'roses', 'reign', 'noble', 'cheap', 'dense', 'linen', 'geese', 'woven', 'posts', 'hired', 'wrath', 'salad', 'bowed', 'tires', 'shark', 'belts', 'grasp', 'blast', 'polar', 'fungi', 'tends', 'pearl', 'loads', 'jokes', 'veins', 'frost', 'hears', 'loses', 'hosts', 'diver', 'phase', 'toads', 'alert', 'tasks', 'seams', 'coral', 'focus', 'naked', 'puppy', 'jumps', 'spoil', 'quart', 'macro', 'fears', 'flung', 'spark', 'vivid', 'brook', 'steer', 'spray', 'decay', 'ports', 'socks', 'urban', 'goals', 'grant', 'minus', 'films', 'tunes', 'shaft', 'firms', 'skies', 'bride', 'wreck', 'flock', 'stare', 'hobby', 'bonds', 'dared', 'faded', 'thief', 'crude', 'pants', 'flute', 'votes', 'tonal', 'radar', 'wells', 'skull', 'hairs', 'argue', 'wears', 'dolls', 'voted', 'caves', 'cared', 'broom', 'scent', 'panel', 'fairy', 'olive', 'bends', 'prism', 'lamps', 'cable', 'peach', 'ruins', 'rally', 'schwa', 'lambs',
         'sells', 'cools', 'draft', 'charm', 'limbs', 'brake', 'gazed', 'cubes', 'delay', 'beams', 'fetch', 'ranks', 'array', 'harsh', 'camel', 'vines', 'picks', 'naval', 'purse', 'rigid', 'crawl', 'toast', 'soils', 'sauce', 'basin', 'ponds', 'twins', 'wrist', 'fluid', 'pools', 'brand', 'stalk', 'robot', 'reeds', 'hoofs', 'buses', 'sheer', 'grief', 'bloom', 'dwelt', 'melts', 'risen', 'flags', 'knelt', 'fiber', 'roofs', 'freed', 'armor', 'piles', 'aimed', 'algae', 'twigs', 'lemon', 'ditch', 'drunk', 'rests', 'chill', 'slain', 'panic', 'cords', 'tuned', 'crisp', 'ledge', 'dived', 'swamp', 'clung', 'stole', 'molds', 'yarns', 'liver', 'gauge', 'breed', 'stool', 'gulls', 'awoke', 'gross', 'diary', 'rails', 'belly', 'trend', 'flask', 'stake', 'fried', 'draws', 'actor', 'handy', 'bowls', 'haste', 'scope', 'deals', 'knots', 'moons', 'essay', 'thump', 'hangs', 'bliss', 'dealt', 'gains', 'bombs', 'clown', 'palms', 'cones', 'roast', 'tidal', 'bored', 'chant', 'acids', 'dough', 'camps', 'swore', 'lover', 'hooks', 'males', 'cocoa', 'punch', 'award', 'reins', 'ninth', 'noses', 'links', 'drain', 'fills', 'nylon', 'lunar', 'pulse', 'flown', 'elbow', 'fatal', 'sites', 'moths', 'meats', 'foxes', 'mined', 'attic', 'fiery', 'mount', 'usage', 'swear', 'snowy', 'rusty', 'scare', 'traps', 'relax', 'react', 'valid', 'robin', 'cease', 'gills', 'prior', 'safer', 'polio', 'loyal', 'swell', 'salty', 'marsh', 'vague', 'weave', 'mound', 'seals', 'mules', 'virus', 'scout', 'acute', 'windy', 'stout', 'folds', 'seize', 'hilly', 'joins', 'pluck', 'stack', 'lords', 'dunes', 'burro', 'hawks', 'trout', 'feeds', 'scarf', 'halls', 'coals', 'towel', 'souls', 'elect', 'buggy', 'pumps', 'loans', 'spins', 'files', 'oxide', 'pains', 'photo', 'rival', 'flats', 'syrup', 'rodeo', 'sands', 'moose', 'pints', 'curly', 'comic', 'cloak', 'onion', 'clams', 'scrap', 'didst', 'couch', 'codes', 'fails', 'ounce', 'lodge', 'greet', 'gypsy', 'utter', 'paved', 'zones', 'fours', 'alley', 'tiles', 'bless', 'crest', 'elder', 'kills', 'yeast', 'erect', 'bugle', 'medal', 'roles', 'hound', 'snail', 'alter', 'ankle', 'relay', 'loops', 'zeros', 'bites', 'modes', 'debts', 'realm', 'glove', 'rayon', 'swims', 'poked', 'stray', 'lifts', 'maker', 'lumps', 'graze', 'dread', 'barns', 'docks', 'masts', 'pours', 'wharf', 'curse', 'plump', 'robes', 'seeks', 'cedar', 'curls', 'jolly', 'myths', 'cages', 'gloom', 'locks', 'pedal', 'beets', 'crows', 'anode', 'slash', 'creep', 'rowed', 'chips', 'fists', 'wines', 'cares', 'valve', 'newer', 'motel', 'ivory', 'necks', 'clamp', 'barge', 'blues', 'alien', 'frown', 'strap', 'crews', 'shack', 'gonna', 'saves', 'stump', 'ferry', 'idols', 'cooks', 'juicy', 'glare', 'carts', 'alloy', 'bulbs', 'lawns', 'lasts', 'fuels', 'oddly', 'crane', 'filed', 'weird', 'shawl', 'slips', 'troop', 'bolts', 'suite', 'sleek', 'quilt', 'tramp', 'blaze', 'atlas', 'odors', 'scrub', 'crabs', 'probe', 'logic', 'adobe', 'exile', 'rebel', 'grind', 'sting', 'spine', 'cling', 'desks', 'grove', 'leaps', 'prose', 'lofty', 'agony', 'snare', 'tusks', 'bulls', 'moods', 'humid', 'finer', 'dimly', 'plank', 'china', 'pines', 'guilt', 'sacks', 'brace', 'quote', 'lathe', 'gaily', 'fonts', 'scalp', 'adopt', 'foggy', 'ferns', 'grams', 'clump', 'perch', 'tumor', 'teens', 'crank', 'fable', 'hedge', 'genes', 'sober', 'boast', 'tract', 'cigar', 'unite', 'owing', 'thigh', 'haiku', 'swish', 'dikes', 'wedge', 'booth', 'eased', 'frail', 'cough', 'tombs', 'darts', 'forts', 'choir', 'pouch', 'pinch', 'hairy', 'buyer', 'torch', 'vigor', 'waltz', 'heats', 'herbs', 'users', 'flint', 'click', 'madam', 'bleak', 'blunt', 'aided', 'lacks', 'masks', 'waded', 'risks', 'nurse', 'chaos', 'sewed', 'cured', 'ample', 'lease', 'steak', 'sinks', 'merit', 'bluff', 'bathe', 'gleam', 'bonus', 'colts', 'shear', 'gland', 'silky', 'skate', 'birch', 'anvil', 'sleds', 'groan', 'maids', 'meets', 'speck', 'hymns', 'hints', 'drown', 'bosom', 'slick', 'quest', 'coils', 'spied', 'snows', 'stead', 'snack', 'plows', 'blond', 'tamed', 'thorn', 'waits', 'glued', 'banjo', 'tease', 'arena', 'bulky', 'carve', 'stunt', 'warms', 'shady', 'razor', 'folly', 'leafy', 'notch', 'fools', 'otter', 'pears', 'flush', 'genus', 'ached', 'fives', 'flaps', 'spout', 'smote', 'fumes', 'adapt', 'cuffs', 'tasty', 'stoop', 'clips', 'disks', 'sniff', 'lanes', 'brisk', 'imply', 'demon', 'super', 'furry', 'raged', 'growl', 'texts', 'hardy', 'stung', 'typed', 'hates', 'wiser', 'timid', 'serum', 'beaks', 'rotor', 'casts', 'baths', 'glide', 'plots', 'trait', 'resin', 'slums', 'lyric', 'puffs', 'decks', 'brood', 'mourn', 'aloft', 'abuse', 'whirl', 'edged', 'ovary', 'quack', 'heaps', 'slang', 'await', 'civic', 'saint', 'bevel', 'sonar', 'aunts', 'packs', 'froze', 'tonic', 'corps', 'swarm', 'frank', 'repay', 'gaunt', 'wired', 'niece', 'cello', 'needy', 'chuck', 'stony', 'media', 'surge', 'hurts', 'repel', 'husky', 'dated', 'hunts', 'mists', 'exert', 'dries', 'mates', 'sworn', 'baker', 'spice', 'oasis', 'boils', 'spurs', 'doves', 'sneak', 'paces', 'colon', 'siege', 'strum', 'drier', 'cacao', 'humus', 'bales', 'piped', 'nasty', 'rinse', 'boxer', 'shrub', 'amuse', 'tacks', 'cited', 'slung', 'delta', 'laden', 'larva', 'rents', 'yells', 'spool', 'spill', 'crush', 'jewel', 'snaps', 'stain', 'kicks', 'tying', 'slits', 'rated', 'eerie', 'smash', 'plums', 'zebra', 'earns', 'bushy', 'scary', 'squad', 'tutor', 'silks', 'slabs', 'bumps', 'evils', 'fangs', 'snout', 'peril', 'pivot', 'yacht', 'lobby', 'jeans', 'grins', 'viola', 'liner', 'comet', 'scars', 'chops', 'raids', 'eater', 'slate', 'skips', 'soles', 'misty', 'urine', 'knobs', 'sleet', 'holly', 'pests', 'forks', 'grill', 'trays', 'pails', 'borne', 'tenor', 'wares', 'carol', 'woody', 'canon', 'wakes', 'kitty', 'miner', 'polls', 'shaky', 'nasal', 'scorn', 'chess', 'taxis', 'crate', 'shyly', 'tulip', 'forge', 'nymph', 'budge', 'lowly', 'abide', 'depot', 'oases', 'asses', 'sheds', 'fudge', 'pills', 'rivet', 'thine', 'groom', 'lanky', 'boost', 'broth', 'heave', 'gravy', 'beech', 'timed', 'quail', 'inert', 'gears', 'chick', 'hinge', 'trash', 'clash', 'sighs', 'renew', 'bough', 'dwarf', 'slows', 'quill', 'shave', 'spore', 'sixes', 'chunk', 'madly', 'paced', 'braid', 'fuzzy', 'motto', 'spies', 'slack', 'mucus', 'magma', 'awful', 'discs', 'erase', 'posed', 'asset', 'cider', 'taper', 'theft', 'churn', 'satin', 'slots', 'taxed', 'bully', 'sloth', 'shale', 'tread', 'raked', 'curds', 'manor', 'aisle', 'bulge', 'loins', 'stair', 'tapes', 'leans', 'bunks', 'squat', 'towed', 'lance', 'panes', 'sakes', 'heirs', 'caste', 'dummy', 'pores', 'fauna', 'crook', 'poise', 'epoch', 'risky', 'warns', 'fling', 'berry', 'grape', 'flank', 'drags', 'squid', 'pelts', 'icing', 'irony', 'irons', 'barks', 'whoop', 'choke', 'diets', 'whips', 'tally', 'dozed', 'twine', 'kites', 'bikes', 'ticks', 'riots', 'roars', 'vault', 'looms', 'scold', 'blink', 'dandy', 'pupae', 'sieve', 'spike', 'ducts', 'lends', 'pizza', 'brink', 'widen', 'plumb', 'pagan', 'feats', 'bison', 'soggy', 'scoop', 'argon', 'nudge', 'skiff', 'amber', 'sexes', 'rouse', 'salts', 'hitch', 'exalt', 'leash', 'dined', 'chute', 'snort', 'gusts', 'melon', 'cheat', 'reefs', 'llama', 'lasso', 'debut', 'quota', 'oaths', 'prone', 'mixes', 'rafts', 'dives', 'stale', 'inlet', 'flick', 'pinto', 'brows', 'untie', 'batch', 'greed', 'chore', 'stirs', 'blush', 'onset', 'barbs', 'volts', 'beige', 'swoop', 'paddy', 'laced', 'shove', 'jerky', 'poppy', 'leaks', 'fares', 'dodge', 'godly', 'squaw', 'affix', 'brute', 'nicer', 'undue', 'snarl', 'merge', 'doses', 'showy', 'daddy', 'roost', 'vases', 'swirl', 'petty', 'colds', 'curry', 'cobra', 'genie', 'flare', 'messy', 'cores', 'soaks', 'ripen', 'whine', 'amino', 'plaid', 'spiny', 'mowed', 'baton', 'peers', 'vowed', 'pious', 'swans', 'exits', 'afoot', 'plugs', 'idiom', 'chili', 'rites', 'serfs', 'cleft', 'berth', 'grubs', 'annex', 'dizzy', 'hasty', 'latch', 'wasps', 'mirth', 'baron', 'plead', 'aloof', 'aging', 'pixel', 'bared', 'mummy', 'hotly', 'auger', 'buddy', 'chaps', 'badge', 'stark', 'fairs', 'gully', 'mumps', 'emery', 'filly', 'ovens', 'drone', 'gauze', 'idiot', 'fussy', 'annoy', 'shank', 'gouge', 'bleed', 'elves', 'roped', 'unfit', 'baggy', 'mower', 'scant', 'grabs', 'fleas', 'lousy', 'album', 'sawed', 'cooky', 'murky', 'infer', 'burly', 'waged', 'dingy', 'brine', 'kneel', 'creak', 'vanes', 'smoky', 'spurt', 'combs', 'easel', 'laces', 'humps', 'rumor', 'aroma', 'horde', 'swiss', 'leapt', 'opium', 'slime', 'afire', 'pansy', 'mares', 'soaps', 'husks', 'snips', 'hazel', 'lined', 'cafes', 'naive', 'wraps', 'sized']


def black_on_gray(text):
    """Return text coloured black, with gray background. Remaining letters."""

    return "\033[0;30;47m"+text+"\033[0m"


def white_on_black(text):
    """Return text coloured white with black background. Not in word."""

    return "\033[5;37;40m"+text+"\033[0m"


def white_on_green(text):
    """Return text coloured white with green background. Correct Position."""

    return "\033[0;37;42m"+text+"\033[0m"


def white_on_yellow(text):
    """Return text coloured white with yellow background. In word, wrong position."""

    return "\033[0;37;43m"+text+"\033[0m"


def get_word(word_list):
    """Return a word randomly chosen from word_list."""

    return random.choice(word_list)


# Rendering Functions
def render_grid(grid):
    # draw grid
    print()
    for i in range(6):
        print(" ", end="")
        for j in range(5):
            if j == 4:
                print(grid[i][j])
            else:
                print(grid[i][j] + " | ", end="")
        if i != 5:
            print(" —   —   —   —   —")


def render_keyboard(keyboard):
    print()
    for i in range(len(keyboard)):
        if (keyboard[i])[10:11] == "A":
            print(" ", end="")
        if (keyboard[i])[10:11] == "Z":
            print("    ", end="")

        print(keyboard[i], end=" ")

        if (keyboard[i])[10:11] == "P" or (keyboard[i])[10:11] == "L" or (keyboard[i])[10:11] == "M":
            print()
    print()


def render_game(grid, keyboard):
    os.system("cls")
    render_grid(grid)
    render_keyboard(keyboard)


# Game utility functions
def get_tutorial():
    # \033[1m makes a string bold
    print("\033[1m"+"Guess the word in 6 tries."+"\033[0m")
    print("  - Each guess must be a valid 5-letter word.")
    print("  - The color of the tiles will change to show how close your guess was\n    to the word.")
    print("\033[1m"+"Examples"+"\033[0m")
    print(white_on_green("W")+"E"+"A"+"R"+"Y")
    print("\033[1m"+"W"+"\033[0m" + " is in the word and in the correct spot.")
    print("P"+white_on_yellow("I")+"L"+"L"+"S")
    print("\033[1m"+"I"+"\033[0m" + " is in the word but in the wrong spot.")
    print("V"+"A"+"G"+white_on_black("U")+"E")
    print("\033[1m"+"U"+"\033[0m" + " is not in the word in any spot.")
    print()
    isContinue = input("Enter \"ok\" to return to game: ").lower()
    if isContinue == "ok":
        return


def get_statistics(num_games, num_wins, max_streak, current_streak, guess_distribution, newest_guess, is_won):
    print("\n\033[1m"+"Statistics"+"\033[0m")

    print("   \033[1m"+str(num_games)+"\033[0m", end="     ")
    print("\033[1m"+str((num_wins/num_games)*100//1) +
          "\033[0m", end="         ")
    print("\033[1m"+str(current_streak)+"\033[0m", end="              ")
    print("\033[1m"+str(max_streak)+"\033[0m")

    print("Played" + " | Win %" + " | Current Streak" + " | Max Streak\n")
    print("\033[1m"+"Guess Distribution"+"\033[0m")
    for i in range(len(guess_distribution)):
        if i == newest_guess:
            if is_won:
                print("{}: {}".format(i, white_on_green(
                    str(guess_distribution[i]))))
            else:
                print("{}: {}".format(i, str(guess_distribution[i])))
        else:
            print("{}: {}".format(i, guess_distribution[i]))
    print()


# Player Functions
def make_guess(guessed_words):
    print("For help, enter \"help\"\n")
    print("Guessed words:", guessed_words)
    guess = input("\nGuess a word: ").lower()
    if guess == "help":
        return "help"
    guessed_words.append(guess)
    # The word occurs in the list
    if WORDS.count(guess) > 0:
        return guess.upper()
    else:
        print("\nThat word doesn't exist")
        if len(guess) != 5:
            print("The word must have 5 letters")
        isContinue = input("\nPress \"ok\" to continue: ").lower()
        return ""


# Gameplay functions
def check_if_won(grid, row, word):
    for i in range(len(word)):
        # Substring is used to get rid of the color sequences to get the actual letter only
        if (grid[row][i])[10:11] != word[i]:
            return False
    return True


def check_and_update(grid, guess, word, row, keyboard):
    # use dictionaries to store the indices (value) where each letter (key) appears in each word
    word_letter_pos_dict = {letter: [] for letter in word}
    guess_letter_pos_dict = {letter: [] for letter in guess}
    for i in range(5):
        word_letter_pos_dict[word[i]].append(i)
        guess_letter_pos_dict[guess[i]].append(i)

    for letter in guess:
        if word.count(letter) > 0:
            # store the indices where each letter is found in the word
            occurrences_in_guess = guess_letter_pos_dict[letter].copy()
            # store the number of occurrences of the letter in the word
            num_occurrences = word.count(letter)
            for pos in guess_letter_pos_dict[letter]:
                # letter occurs in the word
                if word_letter_pos_dict[letter].count(pos) > 0:
                    # green
                    num_occurrences -= 1
                    occurrences_in_guess.remove(pos)
                    grid[row][pos] = white_on_green(guess[pos])
                    # color keyboard green
                    keyboard[keyboard.index((list(filter(lambda x: x[10:11] == guess[pos], keyboard)))[
                        0])] = white_on_green(guess[pos])
                else:
                    # black
                    grid[row][pos] = white_on_black(guess[pos])
                    # color keyboard black
                    keyboard[keyboard.index((list(filter(lambda x: x[10:11] == guess[pos], keyboard)))[
                        0])] = white_on_black(guess[pos])
            # there are still letters left
            if num_occurrences > 0 and len(occurrences_in_guess) > 0:
                # yellow
                for pos in range(min(num_occurrences, len(occurrences_in_guess))):
                    grid[row][occurrences_in_guess[pos]] = white_on_yellow(
                        guess[occurrences_in_guess[pos]])
                    # color keyboard yellow
                    current_key = keyboard[keyboard.index((list(filter(lambda x: x[10:11] == guess[pos], keyboard)))[
                        0])]

                    keyboard[keyboard.index((list(filter(lambda x: x[10:11] == guess[occurrences_in_guess[pos]], keyboard)))[
                        0])] = white_on_yellow(guess[occurrences_in_guess[pos]]) if current_key != white_on_green(guess[occurrences_in_guess[pos]]) else white_on_green(guess[occurrences_in_guess[pos]])
        else:
            # black
            for i in guess_letter_pos_dict[letter]:
                grid[row][i] = white_on_black(guess[i])
                # color keyboard black
                keyboard[keyboard.index((list(filter(lambda x: x[10:11] == guess[i], keyboard)))[
                    0])] = white_on_black(guess[i])
    return [grid, keyboard]


# Driver Code
def main():
    is_continue = True
    is_won = False
    num_games = 0
    num_wins = 0
    max_streak = 0
    current_streak = 0
    is_streak = True
    newest_guess = 7
    is_see_statistics = ""
    guess_distribution = [0, 0, 0, 0, 0, 0]
    guessed_words = []

    # Continue looping after each game until the user wants to exit the game
    while is_continue:
        guessed_words.clear()
        #word = "ERASE"
        word = get_word(WORDS).upper()
        grid = [[" " for i in range(5)] for j in range(6)]
        keyboard = ["Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S",
                    "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M"]
        for i in range(len(keyboard)):
            keyboard[i] = black_on_gray(keyboard[i])

        render_game(grid, keyboard)

        # Driver code for each game
        for i in range(6):
            guess = make_guess(guessed_words)

            while guess == "" or guess == "help":
                if guess == "help":
                    # output.clear()
                    os.system("cls")
                    get_tutorial()
                render_game(grid, keyboard)
                guess = make_guess(guessed_words)

            # check_and_update returns the new grid and letter keyboard, as a list
            new_values = (check_and_update(grid, guess, word, i, keyboard))
            grid = new_values[0]
            keyboard = new_values[1]
            render_game(grid, keyboard)

            if check_if_won(grid, i, word):
                print("Congratulations! You guessed the word!")
                is_won = True
                is_streak = True
                if is_streak:
                    current_streak += 1
                num_wins += 1
                guess_distribution[i] += 1
                newest_guess = i
                break

        if current_streak > max_streak:
            max_streak = current_streak
        num_games += 1

        if not is_won:
            print("The word was {}".format(word))
            is_streak = False
            current_streak = 0

        is_see_statistics = input("See statistics (y/n)? ").lower()
        if is_see_statistics == "y":
            # output.clear()
            os.system("cls")
            get_statistics(num_games, num_wins, max_streak,
                           current_streak, guess_distribution, newest_guess, is_won)

        is_won = False
        stop_or_continue = input(
            "Would you like to play again (y/n)? ").lower()
        if stop_or_continue == "y":
            is_continue = True
            os.system("cls")
        else:
            is_continue = False
            # output.clear()
            os.system("cls")


main()
