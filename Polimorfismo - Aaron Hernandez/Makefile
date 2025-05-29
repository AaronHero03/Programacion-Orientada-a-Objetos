CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
TEST_DIR = tests
SRC_DIR = src

# Lista de todos los tests
TESTS = $(wildcard $(TEST_DIR)/Testing_Ejercicio_*.cpp)
TEST_EXES = $(TESTS:$(TEST_DIR)/%.cpp=$(TEST_DIR)/%)

# Regla para compilar todos los tests
all_tests: $(TEST_EXES)

# Regla genérica para compilar tests
$(TEST_DIR)/%: $(TEST_DIR)/%.cpp include/MatrixOp.h src/MatrixOp.cpp
	$(CXX) $(CXXFLAGS) $< src/MatrixOp.cpp -o $@

# Regla para ejecutar todos los tests
test: all_tests
	@echo "Ejecutando todas las pruebas..."
	@for test in $(TEST_EXES); do \
		echo; \
		echo "=== Ejecutando $$test ==="; \
		$$test; \
	done

clean:
	rm -f $(TEST_DIR)/test_*