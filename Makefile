IDIR=include
CC=g++
CFLAGS=-I $(IDIR) -std=c++11

STRDIR=strategies
SIMDIR=game

OUTDIR=out
OUTSTR=$(OUTDIR)/$(STRDIR)
OUTSIM=$(OUTDIR)/$(SIMDIR)

STRHEADER=$(IDIR)/strategy.h
STRATEGIES_CPP=$(wildcard $(STRDIR)/*.cpp)
STRATEGIES_OBJ=$(addprefix $(OUTSTR)/,$(notdir $(STRATEGIES_CPP:.cpp=.o)))

SIM_CPP=$(wildcard $(SIMDIR)/*.cpp)
SIM_H=$(addprefix $(IDIR)/,$(notdir $(SIM_CPP:.cpp=.h)))
SIM_OBJ=$(addprefix $(OUTSIM)/,$(notdir $(SIM_CPP:.cpp=.o)))

game: $(STRATEGIES_OBJ) $(SIM_OBJ)
	$(CC) -o $(OUTDIR)/pr_dilemma $^ $(CFLAGS)

$(OUTSTR)/%.o: $(STRDIR)/%.cpp $(STRDIR)/%.h  $(STRHEADER) | dir
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTSIM)/%.o: $(SIMDIR)/%.cpp $(SIM_H) | dir
	$(CC) -c -o $@ $< $(CFLAGS)

dir:
	mkdir -p $(OUTSTR)
	mkdir -p $(OUTSIM)

clean:
	rm -rf $(OUTDIR)
