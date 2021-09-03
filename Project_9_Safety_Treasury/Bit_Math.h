

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SETBIT(REG,BITNO)	((REG)|=(1<<(BITNO)))
#define CLRBIT(REG,BITNO)	((REG)&=(~(1<<(BITNO))))
#define ROGGEL(REG,BITNO)	((REG)^(1<<BITNO))
#define GETBIT(REG,BITNO)	((REG)&(1<<BITNO))

#endif /* BIT_MATH_H_ */
