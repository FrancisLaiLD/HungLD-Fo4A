.PHONY: clean All

All:
	@echo "----------Building project:[ Fo4A - Debug ]----------"
	@cd "Fo4A" && "$(MAKE)" -f  "Fo4A.mk"
clean:
	@echo "----------Cleaning project:[ Fo4A - Debug ]----------"
	@cd "Fo4A" && "$(MAKE)" -f  "Fo4A.mk" clean
