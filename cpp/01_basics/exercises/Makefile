# Compiler und Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
DEBUGFLAGS = -g -O0

# Verzeichnisse
SRCDIR = .
BUILDDIR = build
TARGETDIR = bin

# Automatische Erkennung aller .cpp Dateien im Quellverzeichnis
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TARGETS = $(patsubst $(SRCDIR)/%.cpp,$(TARGETDIR)/%,$(SOURCES))

# Standardziel
all: $(TARGETS)

# Regeln für einzelne Ziele
$(TARGETDIR)/%: $(BUILDDIR)/%.o
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug-Versionen
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean all

# Einzelne Datei kompilieren (Verwendung: make single FILE=dateiname)
single: $(BUILDDIR)/$(FILE).o
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $< -o $(TARGETDIR)/$(FILE)

# Debug-Version einer einzelnen Datei
debug_single: CXXFLAGS += $(DEBUGFLAGS)
debug_single: single

# Ausführen eines spezifischen Programms
run:
	@if [ -z "$(FILE)" ]; then \
		echo "Bitte geben Sie eine Datei an: make run FILE=dateiname"; \
	else \
		$(TARGETDIR)/$(FILE); \
	fi

# Ausführen im LLDB
debug_run:
	@if [ -z "$(FILE)" ]; then \
		echo "Bitte geben Sie eine Datei an: make debug_run FILE=dateiname"; \
	else \
		lldb $(TARGETDIR)/$(FILE); \
	fi

# Aufräumen
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)

.PHONY: all debug single debug_single run debug_run clean