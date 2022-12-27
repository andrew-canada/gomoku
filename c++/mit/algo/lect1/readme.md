# algo 1

## goals
- communication
  1. solve computational problems
  2. prove correctness
  3. efficiency

## what is an algorithm
- function : input->output
- is general and can change, based on arbitrarily-sized inputs

## how to prove algorithm correctness
- induction:
 - base case
   - predicate : returns true or false
 - hypothesis : has an incrementable variable

## algorithm efficiency
- how fast is an algorithm? how fast when compared to other possible solutions?
- don't measure time, count operations needed
- expect performance to depend on input size (N)
- types of measurement
  - O(.) : upper bound
  - B(.) : lower bound
  - Omega : both

## model of computation
- word-RAM
  - largest size of word cpu can take from memory (64bit cpu can take 64 bit word)
  - 32-bit limits cpu recieveing to 4gb


## what is a computation problem
- binary relation of inputs and outputs
- define a problem:
  - predicates : given an input, is it in a set of outputs?
  - has a range of cases

## todo
- pidgeon hole principle
- induction
- asymptotic analysis
- word-RAM
