# Fixed Point Is Hell (FPIH)

Fixed point mathematics are a mainstay of embedded performant compute; they are also horrible to work with. Lets fix that.

## Objectives

Quick to pick up and work with straight away but performant, verifiable and scalable enough to enter production:

 - **Quick to pick up**: 
    - Single C(++) header
    - Simple functions with clear use cases
 - **Performant**:
    - Intrinsic compatible primatives  
    - Optimise the range-precision tradeoff intrinsic to fixed point numbers
 - **Verifiable**
    - Range-precision tradeoff and overflow/underflow detection front and centre during development  
    - Floating point vs. fixed point algorithm testing framework (todo: tighten this up) 
    - No undefined behaviour  

## Requirements

There are none.

Docker is required for testing.

## Testing

 1. Ensure Docker is installed
 2. Run `run_tests.sh` script 

## Credit 

 - Heavily influenced by: https://github.com/mgetka/fptc-lib
 - todo: link all the code/papers you've stolen