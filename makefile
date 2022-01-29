BUILD_DIR:=build
LIBS:=FCFS PriorityScheduling RoundRobin SJF SRTF

ifeq ($(OS),Windows_NT)
    EXT:=dll
else
    EXT:=so
endif

D_LIBS:=$(patsubst %,%.$(EXT),$(LIBS))
EXEC:=main

.PHONY: target
target: create_build_directory Node.$(EXT) $(D_LIBS) $(EXEC)

.PHONY: create_build_directory
create_build_directory:
	@mkdir -p $(BUILD_DIR)
	
Node.$(EXT): Node.cpp
	@echo Generating shared library: $@
	@g++ -shared -g -fPIC -o $(BUILD_DIR)/$@ $?

%.$(EXT): %.cpp
	@echo Generating shared library: $@
	@g++ -shared -g -fPIC -L$(BUILD_DIR) -l:Node.$(EXT) -o $(BUILD_DIR)/$@ $?

$(EXEC): $(EXEC).cpp
	@echo Generating executable: $@
	@g++ -g $< -L$(BUILD_DIR) $(patsubst %,-l:%,$(D_LIBS)) -l:Node.$(EXT) -o $(BUILD_DIR)/$@

.PHONY: print-%
print-%:
	@echo $*=$($*)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
