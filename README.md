# Prisoner's Dilemma
Simulator for the [Prisoner's dilemma](https://en.wikipedia.org/wiki/Prisoner's_dilemma) game with an ability of adding new strategies without any changes in other files.

## Usage
Simulator gets following arguments:
- Three (or more for tournament mode) strategy names
- Number of simulation steps ```--steps=<n>```
- Simulation mode ```--mode=[detailed|fast|tournament]``` (optional, default: ```detailed``` for 3 strategies and ```tournament``` for 4 or more)
- Directory with configuration files for strategies ```--configs=<dirname>``` (optional)
- File with game matrix ```--matrix=<filaname>``` (optional)

e.g.  ```./pr_dilemma angry eyeForEye kind master slave slave --steps=100 --mode=tournament --configs=../configs/```

## How to run

	make
	cd out/
	./pr_dilemma <...>

## List of default available strategies
- angry
- eyeForEye
- fifty-fifty
- kind
- master
- slave
- smartAngry
	
## Add your own strategy
- You need to extend ```Strategy``` class
- Include ```factory.h``` and ```creator.h``` and register your strategy, for example using this construction ```bool c = Instance<std::string>().Register(<strategy name>, &Creator< <your class name> >);```  (```creator.h``` is not neccessary, you can use your own functor/fuction/lambda etc.)
- Implement ```void GetResults(Choiсe a, Choiсe b)``` method, which provides you with the results of two opponents, you can ignore it or make some conclusions
- Implement  ```Strategy::Choice YourStrategy::MakeChoice()```, where you make your decision
- Place ```yourStrategy.cpp``` and ```yourStrategy.h``` in ```strategies/``` folder and run ```make```

See examples of simple [```random```](https://github.com/saltukkos/study/blob/master/c%2B%2B/Prisoner's-dilemma/strategies/rndStrategy.cpp) strategy and metastrategy [```master```](https://github.com/saltukkos/study/blob/master/c%2B%2B/Prisoner's-dilemma/strategies/masterStrategy.cpp), which use many [```slave```](https://github.com/saltukkos/study/blob/master/c%2B%2B/Prisoner's-dilemma/strategies/slaveStrategy.cpp) to win.

## Current results table
Current tournament results depends on number of ```slave``` strategies playing the game, which allows ```master``` to win. 
For justice we use only one instance of every strategy.

![](https://docs.google.com/spreadsheets/d/1yp0ikQj1VOjHpww1VW2flAwW6Vh1nLs3xC2YzeDzhPk/pubchart?oid=731440815&format=image) 