.PHONY: clean All

All:
	@echo "----------Building project:[ mytest - Debug ]----------"
	@cd "mytest" && "$(MAKE)" -f  "mytest.mk"
clean:
	@echo "----------Cleaning project:[ mytest - Debug ]----------"
	@cd "mytest" && "$(MAKE)" -f  "mytest.mk" clean
