README
ProjektarbeitDiffusion Version 1.0  13.07.2014
----------------------------------
Programm:
---------
ProjektarbeitDiffusion geschrieben in C++
Programmiert für Linux
Grafikoutput benötigt Gnuplot Version 4.6

Zielsetzung:
------------
Darstellung des Diffusionsprozesses.
->zentraler Stoß

Input:
------
->Es werden die Randbedingungen für den Diffusionsprozess* eingegeben.
*in einem durch einen Spalt zweigeteilten rechteckigem Kasten

Output:
-------
->Es werden bei jedem Schritt Gifs und Plots zur Verteilung der Teilchen erzeugt.
->Zum Schluss wird die Verteilung der Anzahl der benötigten Iterationen geplottet.
->Mittelwert und Randwerte werden explizit ausgegeben

Beispiel:
---------
Programm mit cmake bauen und compilieren, danach ausführen:
Eigaben:
10	5	0	1	1	1	0.5	0.5	0	0.05
Falls gespeichert werden soll Plots und Gifs an einem anderen Ort speichern, dann Enter drücken ...


Inhalt:
-------
->README:
	README.txt
->LatexManual:
	Manual.tex
->Source:
	CMakeLists.txt
	Kasten.h		Kasten.cpp
	Teilchen.h		Teilchen.cpp
	Teilchengernerator.h	Teilchengernerator.cpp
	Ausgleich.h		Ausgleich.cpp
	Grafikoutput.h		Grafikoutput.cpp
	Eingaben.h		Eingaben.cpp
				ProjektarbeitDiffusion.cpp
->Doxygen:
	Doxy-Diffusion.Doxyfile
->CMake:
	CMakeLists.txt
->Präsentation:
	VortragDiffusion.tex
	Ausgleich.png
	Eingaben.png
	Flussdiagramm_main.png
	Grafikoutput.png
	Iterations_verteilung.png
	Kasten.png
	Teilchen.png
	Teilchengernerator.png
	UML-Projektarbeit.png
	Verteilung_100.png
	Verteilung_200.png
	Verteilung_300.png
