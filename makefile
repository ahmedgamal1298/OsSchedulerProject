BUILD_DIR:=build
LIBS:=Node FCFS PriorityScheduling RoundRobin SJF SRTF
D_LIBS:=$(patsubst %,%.so,$(LIBS))
EXEC:=main

.PHONY: target
target: create_build_directory $(D_LIBS) $(EXEC)

.PHONY: create_build_directory
create_build_directory:
	@mkdir -p $(BUILD_DIR)

%.so: %.cpp
	@g++ -shared -g -fPIC -o $(BUILD_DIR)/$@ $?

$(EXEC): $(EXEC).cpp
	@g++ -g $< -L$(BUILD_DIR) $(patsubst %,-l:%,$(D_LIBS)) -o $(BUILD_DIR)/$@

.PHONY: print-%
print-%:
	@echo $*=$($*)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
