# Настройки компилятора
CXX = g++
CFLAGS = -Wall -Werror -Wextra -std=c++20 -O0
LDFLAGS = -lgtest -lgcov --coverage -pthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage # то же самое одним флагом --coverage 

# Находим все .c и .h файлы во всех поддиректориях
SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

# Директории
BUILD_DIR = build
DIR = .
TEST_DIR = test
COVERAGE_DIR = coverage
COVERAGE_INFO = $(COVERAGE_DIR)/coverage.info
COVERAGE_HTML = $(COVERAGE_DIR)/html

# Исходные файлы
LIB_FILE = $(wildcard $(DIR)/*.cpp)
TEST_FILE = $(wildcard $(TEST_DIR)/*.cpp)

# Генерация имен объектных файлов
LIB_OBJ = $(patsubst $(DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_FILE))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILE))

# Целевые файлы
LIBRARY = $(BUILD_DIR)/s21_matrix_oop.a
TEST = $(BUILD_DIR)/test

# Создание директории сборки
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Правило компиляции .o из .c
$(BUILD_DIR)/%.o: $(DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

# Cоздание статической библиотеки (архива объектных файлов)
$(LIBRARY): $(LIB_OBJ)
	ar rcs $@ $^

# Сборка исполняемого файла
$(TEST): $(TEST_OBJ) $(LIBRARY)	
	$(CXX) $(CFLAGS) $^ $(LDFLAGS) -o $@	

# Phony targets
.PHONY: all \		  	
		test \
		gcov_report \			
		clang_format \
		valgrind \
		clean \
		s21_matrix_oop.a

all: gcov_report

test: $(LIBRARY) $(TEST)
	@cd $(BUILD_DIR) && ./test

gcov_report: test
	@mkdir -p $(COVERAGE_DIR)
# Генерация lcov отчёта
	lcov --capture --directory . --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_DIR)/coverage.info '/usr/*' --output-file $(COVERAGE_DIR)/filtered.info
# Генерация HTML
	genhtml $(COVERAGE_DIR)/filtered.info -o $(COVERAGE_HTML)
	@echo "Отчёт доступен в $(COVERAGE_HTML)/index.html"

s21_matrix_oop.a: $(LIBRARY)
		
clang_format:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SRCS) $(HDRS)
	clang-format -i $(SRCS) $(HDRS)
	rm -f .clang-format

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all  --track-origins=yes --tool=memcheck --log-file=$(TEST_DIR)/valgrind_test.txt $(TEST)

clean:
	@rm -rf $(BUILD_DIR) $(COVERAGE_DIR)
	@rm -f $(TEST_DIR)/valgrind_test.txt