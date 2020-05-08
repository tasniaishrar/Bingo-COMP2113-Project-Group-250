winCombo.o: winCombo.cpp winCombo.h
  g++ -c $^ 

repCheck.o: repCheck.cpp repCheck.h
  g++ -c $^

printCard.o: printCard.cpp printCard.h
  g++ -c $^

nextMove.o: nextMove.cpp nextMove.h printCard.cpp printCard.h generateNumber.cpp generateNumber.h
  g++ -c $^

isValidSize.o: isValidSize.cpp isValidSize.h
  g++ -c $^

getInput.o: getInput.cpp getInput.h isValidSize.cpp isValidSize.h
  g++ -c $^

getChoice.o: getChoice.cpp getChoice.h
  g++ -c $^

generateNumber.o: generateNumber.cpp generateNumber.h
  g++ -c $^

generateCard.o: generateCard.cpp generateCard.h generateNumber.cpp generateNumber.h printCard.cpp printCard.h repCheck.cpp repCheck.h
  g++ -c $^

claimBingo.o: claimBingo.cpp claimBingo.h winCombo.cpp winCombo.h
  g++ -c $^

autoCheck.o: autoCheck.cpp autoCheck.h
  g++ -c $^

main.o: main.cpp getInput.h generateCard.h getChoice.h nextMove.h claimBingo.h autoCheck.h
  g++ -c $^

main: main.o getInput.o generateCard.o getChoice.o nextMove.o claimBingo.o autoCheck.o
  g++ $^ -o $@

