using std::string; using std::cout; using std::vector;

struct speise
{
	short ID;
	string Bezeichnung;
	string Beschreibung;
	float Preis;
};

std::vector<speise> menu {
	//Für unsere kleinen Gäste
	{0, "Spaghetti", "Tomatensauce", 4.00f},
	{1, "Penne", "Bolognesesauce ", 4.50f},
	{2, "Mickey Mouse", "Pizza Margherita ", 5.00f},
	{3, "Mickey Mouse", "Pizza Salami ", 6.00f},
	{4, "Mickey Mouse", "Pizza Schinken ", 6.00f},
	//Vom Schwein
	{5, "Cotoletta alla Milanese", "Paniertes Schnitzel", 8.50f},
	{6, "Scaloppina ai Funghi", "Schweinerückensteak in Champignonsauce", 12.50f},
	//Vom Kalb
	{7, "Scaloppina al Vino Bianco", "Kalbsmedaillon in Weißweinsauce", 14.0f},
	{8, "Scaloppina al sugo di Gorgonzola", "Kalbsmedaillon mit Gorgonzolasauce", 14.0f},
	//Vom Rind
	{9, "Filetto ai Ferri", "Filet gegrillt", 17.50f},
	//Fisch
	{10, "Calamari fritti", "Tintenfisch paniert", 11.50f},
	{11, "Calamari al sugo", "Tintenfisch, Oliven und Tomatensauce", 14.50f},
	//Nudeln
	{12, "Penne all arrabbiata", "hausgemachte Tomatensauce, scharf", 7.0f},
	{13, "Penne all pesto", "Basilikum, Schafskäse und Knoblauch", 8.0f},
	{14, "Penne Rucola", "Rucola und Tomatensauce", 7.0f},
	{15, "Rigatoni Aurora", "Schinken, Sahne- und Tomatensauce", 6.50f},
	{16, "Rigatoni al Funghi", "frische Champignons und Sahnesauce", 7.0f},
	{17, "Rigatoni al forno", "Schinken, Sahne- und Tomatensauce, überbacken", 7.0f},
	{18, "Rigatoni quattro formaggi", "vier Käsesorten und Sahnesauce", 7.50f},
	{19, "Rigatoni alla Amatriciana", "scharfe Tomatensauce, Zwiebeln und Speck", 7.50f},
	{20, "Tortellini Casa", "Erbsen, Schinken und Sahnesauce", 7.50f},
	{21, "Tortellini al Casa", "Schinken, Sahne- und Tomatensauce, überbacken", 8.0f},
	{22, "Spaghetti Napoli", "Tomatensauce", 6.00f},
	{23, "Spaghetti Bolognese", "Hackfleischsauce", 6.50f},
	{24, "Spaghetti aglio e olio", "Knoblauch und Olivenöl", 6.50f},
	{25, "Spaghetti Siciliana", "Kapern, Oliven, Sardellen und Tomatensauce", 7.50f},
	{26, "Spaghetti Carbonara", "Speck, Ei und Sahnesauce", 7.50f},
	{27, "Spaghetti Mare", "Meersfrüchte, Tomatensauce, mit Weiáwein verfeinert", 8.50f},
	{28, "Tagliatelle Boscaiola", "Champignons, Schinken, Erbsen mit Tomaten- und Sahnesauce überbacken", 8.50f},
	{29, "Tagliatelle Cartoccio", "Filet, Champignons, Schinken und Weißwein, überbacken", 9.00f},
	{30, "Fusilli gorgonzola e spinaci", "Spinat, Gorgonzola und Sahne", 7.50f},
	{31, "Fusilli alla marco polo", "Parmaschinken, Champignons, Pesto und Tomatensauce", 8.50f},
	{32, "Fettucine all salmone", "Lachs und Tomatensauce", 8.50f},
	{33, "Fettucine con pollo", "Hühnerbruststreifen, Sahne- und Tomatensauce", 8.50f},
	{34, "Fettucine con gamberetti", "Shrimps, Rucola und Tomatensauce, mit Weißwein verfeinert ", 8.50f},
	{35, "Cannelloni bolognese alla casa", "hausgemachte Cannelloni mit Hackfleisch, Erbsen und Tomatensauce, überbacken ", 7.50f},
	{36, "Cannelloni spinaci alla casa ", "hausgemachte Cannelloni mit Spinat und Sahnesauce, überbacken", 7.50f},
	{37, "Lasagne al forno alla casa", "hausgemachte Lasagne mit Hackfleisch, Bechamel- und Tomatensauce", 7.00f},
	{38, "Combinazione", "Rigatoni, Cannelloni, Tortellini mit Tomatensauce, überbacken ", 7.50f},
	//Pizza
	{39, "Pizza Quattro Stagioni (klein)", "Schinken, Salami, Champignons, Peperoni, Artischocken", 6.50f},
	{40, "Pizza Quattro Stagioni (groß)", "Schinken, Salami, Champignons, Peperoni, Artischocken", 7.50f},
	{41, "Pizza Quattro Formaggi (klein)", "vier Käsesorten", 6.50f},
	{42, "Pizza Quattro Formaggi (groß)", "vier Käsesorten", 7.50f},
	{43, "Pizza Marinara (klein)", "Kapern, Oliven, Sardellen, Knoblauch", 6.50f},
	{44, "Pizza Marinara (groß)", "Kapern, Oliven, Sardellen, Knoblauch", 7.50f},
	{45, "Pizza Calzone (klein)", "Schinken, Salami, Champignons", 6.50f},
	{46, "Pizza Calzone (groß)", "Schinken, Salami, Champignons", 7.50f},
	{47, "Pizza Mare (klein)", "Meeresfrüchte", 7.50f},
	{48, "Pizza Mare (groß)", "Meeresfrüchte", 8.50f},
	{49, "Pizza Parma (klein)", "Parmaschinken", 7.50f},
	{50, "Pizza Parma (groß)", "Parmaschinken", 8.50f},
	{51, "Pizza Gamberetti (klein)", "Shrimps", 7.50f},
	{52, "Pizza Gamberetti (groß)", "Shrimps", 8.50f},
	{53, "Pizza Bardolino (klein)", "Spinat, Tomaten, Mozzarella", 7.50f},
	{54, "Pizza Bardolino (groß)", " Spinat, Tomaten, Mozzarella", 8.50f},
	{55, "Pizza Vegetariana (klein)", "frisches Gemüse der Saison", 7.50f},
	{56, "Pizza Vegetariana (groß)", "frisches Gemüse der Saison", 8.50f},
	{57, "Pizza Marco Polo (klein)", "Spinat, Broccoli, Gorgonzola", 7.50f},
	{58, "Pizza Marco Polo (groß)", "Spinat, Broccoli, Gorgonzola", 8.50f},
	{59, "Pizza Pane (klein)", "Pizza Brot ", 3.00f},
	{60, "Pizza Pane (groß)", "Pizza Brot ", 4.00f},
	{61, "Pizza Margherita (klein)", "Tomaten und Käse", 5.00f},
	{62, "Pizza Margherita (groß)", "Tomaten und Käse", 6.00f},
	{63, "Pizza Salami (klein)", "Salami", 5.50f},
	{64, "Pizza Salami (groß)", "Salami", 6.50f},
	{65, "Pizza funghi (klein)", "Champignons", 5.50f},
	{66, "Pizza funghi (groß)", "Champignons", 6.50f},
	{67, "Pizza Prosciutto (klein)", "Schinken", 5.50f},
	{68, "Pizza Prosciutto (groß)", "Schinken", 6.50f},
	{69, "Pizza Carciofi (klein)", "Artischocken", 5.50f},
	{70, "Pizza Carciofi (groß)", "Artischocken", 6.50f},
	{71, "Pizza Acciughe (klein)", "Sardellen", 5.50f},
	{72, "Pizza Acciughe (groß)", "Sardellen", 6.50f},
	{73, "Pizza Aglio (klein)", "Knoblauch", 5.50f},
	{74, "Pizza Aglio (groß)", "Knoblauch", 6.50f},
	{75, "Pizza Bolognese (klein)", "Hackfleischsauce", 5.50f},
	{76, "Pizza Bolognese (groß)", "Hackfleischsauce", 6.50f},
	{77, "Pizza Arrabiata (klein)", "scharf", 5.50f},
	{78, "Pizza Arrabiata (groß)", "scharf", 6.50f},
	{79, "Pizza Anna Maria (klein)", "Schinken und Zwiebeln ", 6.00f},
	{80, "Pizza Anna Maria (groß)", "Schinken und Zwiebeln ", 7.00f},
	{81, "Pizza Roma (klein)", "Schinken und Champignons ", 6.00f},
	{82, "Pizza Roma (groß)", "Schinken und Champignons ", 7.00f},
	{83, "Pizza Pugliese (klein)", "Salami und Peperoni ", 6.00f},
	{84, "Pizza Pugliese (groß)", "Salami und Peperoni ", 7.00f},
	{85, "Pizza Broccoli (klein)", "Broccoli", 6.00f},
	{86, "Pizza Broccoli (groß)", "Broccoli", 7.00f},
	{87, "Pizza Rucola (klein)", "Rucola",  6.00f},
	{88, "Pizza Rucola (groß)", "Rucola",  7.00f},
	{89, "Pizza Tonno (klein)", "Thunfisch", 6.00f},
	{90, "Pizza Tonno (groß)", "Thunfisch", 7.00f},
	{91, "Pizza Mozzarella (klein)", "Mozzarella", 6.50f},
	{92, "Pizza Mozzarella (groß)", "Mozzarella", 7.50f},
	{93, "Pizza Mafia (klein)", "scharfe Salami ", 6.50f},
	{94, "Pizza Mafia (groß)", "scharfe Salami ", 7.50f},
	{95, "Pizza Montanara (klein)", "Zwiebeln, Schinken, und Ei", 6.50f},
	{96, "Pizza Montanara (groß)", "Zwiebeln, Schinken, und Ei", 7.50f},
	{97, "Pizza Speziale (klein)", "Schinken, Salami, Champignons", 6.50f},
	{98, "Pizza Speziale (groß)", "Schinken, Salami, Champignons", 7.50f},
	{99, "Pizza Gorgonzola (klein)", "Gorgonzolakäse", 6.50f},
	{100, "Pizza Gorgonzola (groß)", "Gorgonzolakäse", 7.50f},
	//Salate
	{101, "Insalata verde", "grüner Salat", 3.00f},
	{102, "Insalata di pomodori", "Tomatensalat", 3.00f},
	{103, "Insalata mista", "gemischter Salat", 4.00f},
	{104, "Insalata verde e tonno", "Grüner Salat mit Thunfisch", 4.00f},
	{105, "Insalata mista e pecorino Fresco", "Gemischter Salat mit Schafskäse", 5.00f},
	{106, "Insalata mista con tonno", "Gemischter Salat mit Thunfisch", 5.00f},
	{107, "Insalata marco polo", "Gemischter Salat mit Thunfisch und Schafskäse", 6.00f},
	//Omelettes
	{108, "Omeletto natura", "", 4.50f},
	{109, "Omeletto romana", "Schinken und Champignons", 5.50f},
	//Vorspeisen
	{110, "Caprese", "Frische Tomaten und Mozzarella", 6.50f},
	{111, "Insalata ai Frutti di Mare", "Meeresfrüchtesalat", 7.50f},
	{112, "Antipasto misto", "Gemischte italienische Vorspeise", 8.00f},
	{113, "Antipasto di verdura", "Gemischte italienische Gemüsevorspeise", 8.00f},
	{114, "Insalata mista con salmone ", "Gemischter Salat mit Lachs", 8.00f},
	//Suppen
	{115, "Minestra in brodo ", "Nudelsuppe", 4.00f},
	{116, "Zuppa di pomodori ", "Tomatencremesuppe", 4.00f},
	{117, "Minestrone", "Gemüsesuppe", 4.50f},
	{118, "Tortellini in brodo", "Tortellinisuppe", 4.50f}
};