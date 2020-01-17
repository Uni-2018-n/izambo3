Αντωνης Καλαμακης SDI1800056
//πες για tostring clone equal κλπ
για λογους δοκιμων και ευκολια αναγνωσης του output χρησιμοποιω την DEBUG για να εμφανιζω ή οχι
τα μηνυματα των constructor

Για την class Object:

προσθεθεικε μια μεταβλιτη static int temp_id, η οποια χρησιμοποιειται για να αναθεσω τιμη στην id
Οι private μεταβλητες της Object εχουν γινει protected για να υπαρχει προσβαση των μεταβλητων στις υποκλασεις
η Object::equal ελεγχει αν δυο αντεικιμενα ειναι ισα συγγρινοντας τα στοιχεια τους και επιστρεφοντας
την καταληλη boolean τιμη.
Η Object::identical ελεγχει αν δυο αντικειμενα εχουν την ιδια θεση μνημης. Η συναρτηση αυτη δεν ειναι virtual
γιατι αν το Object κομματι της κλασης ειναι στην ιδια θεση μνημης τοτε και το υπολοιπο θα ειναι.
Η Object::clone ειναι pure virtual γιατι οι υποπλασεις της μπορουν και κανουν clone και το κομματι
της υπερκλασης τους.




Για την class String:
υποκλαση της Object, σαν κειμενο εχω την std::string txt η οποια αρχικοποιειται κατα τον constructor
της String.
Υπαρχουν δυο concat για λογους ευκολιας, μια η οποια συγχωνευει 2 String αντεικιμενα και μια η οποια
περνει ως παραμετρους ενα string και το ενονει με το txt της String μας.
Η String::clone δημιουργει εναν String* temp, ο οποιος εχει δεδομενα τα δεδομενα του this. Επισης αντιγραφονται
και οι τιμες στο κομματι της υπερκλασης Object, με την βοηθεια της protected των private μεταβλιτων της Object.
Τελος επιστρεφει το temp για να γινει η αναθεση του.
Η String::toString, δημιουργει ενα String temp το οποιο περνει σαν ορισμα την περιγραφη της υπερκλασης(Object::toString)
πλας την περιγραφη του String κομματιου της κλασης.
Η String::equal ελεγχει πρωτα την υπερκλαση της και μετα το δικο της μελος



Για την class Employee:
υποκλαση της Object, κατα την δημιουργια της περνει ως ορισμα μια αναφορα σε String για να αρχικοποιηθει το ονομα του Employee
Οι private μεταβλητες της ειναι protected για να εχουν προσβαση οι υποκλασεις της σε αυτες.
Η Employee::equal καλει την equal της υπερκλασης της(Object::equal) και αναλογα το αποτελεσμα που θα βγαλει, ελεγχει αν στο
κομματι της class Employee τα στοιχεια ειναι ιδια με το sec. Αν ναι επιστρεφει την καταληλη boolean τιμη.
Οι Employee::workOn και Employee::report συναρτησεις της Employee ειναι "pure virtual" συναρτησεις(δηλαδη ειναι κενες) οχι
με τον τροπο, virtual void foo()=0, γιατι καποιες υποκλασεις της κλασης Employee δεν χρειαζονται ολες τις συναρτησεις της,
αρα για να μην υπαρχει ο περιορισμος ειναι κενες virtual συναρτησεις.
Η Employee::toString δημιουργει εναν String temp ο οποιος περνει ως ορισμα την περιγραφη της υπερκλασης της και προσθετει
το δικο της κομματι της περιγραφης και το επιστρεφει.
Η Employee::clone ειναι pure virtual γιατι οι υποπλασεις της μπορουν και κανουν clone και το κομματι
της υπερκλασης τους.

Για την class SecurityEmployee:
Υποκλαση της Employee, κατα την δημιουργια της περνει ως ορισμα μια αναφορα σε String και το κανει clone στην Employee::name
Υπαρχουν 3 SecurityEmployee::workOn οι οποιες ειναι μια για καθε χωρο που πρεπει να δουλεψει ο SecurityEmployee. Αυτες εκτυπωνουν
ενα μηνυμα το οποιο λεει οτι ο εργατης ξεκινησε να δουλευει στον συγγεκριμενο χωρο και καλουν την proccess του χωρου με ορισμα
το *this(τον εργατη δηλαδη) για ενημερωσουν οτι ο συγκεκριμενος εργατης δουλεψε στον χωρο.
Υπαρχουν επισης 3 SecurityEmployee::report οι οποιες για καθε χωρο που πρεπει να δουλεψει ο SecurityEmployee εκτυπωνει
και αλλο μηνυμα οτι συνεχιζει να δουλευει στον συγγεκριμενο χωρο.
Η SecurityEmployee::equal ελεγχει αν το Employee κομματι του αντικειμενου ειναι equal και επιστρεφει την αντιστηχη boolean τιμη
(αφου δεν χρειαζεται να ελεγξει αλλα δεδομενα).
Η SecurityEmployee::clone δημιουργει ενα temp αντικειμενο και αντιγραφει σε αυτο τα δεδομενα των υπερκλασεων του, τελος το επιστρεφει
Η SecurityEmployee::toString δημιουργει ενα String temp το οποιο περνει ως ορισμα την περιγραφη της υπερκλασης της και προσθετει
και το δικο της κομματι της περιγραφης, τελος το επιστρεφει

Οι κλασεις CleaningEmployee και MaintenanceEmployee ειναι ιδιες με την SecurityEmployee αλλα διαφερουν στα μηνυματα.

Επισης η κλαση CleaningEmployee εχει μια εξτρα workOn/process, για τον χωρο CargoBay στον οποιο δεν πρεπει να δουλευει,
αλλα ο CargoBay εχει μεσα ενα Equipment_space Και επειδη ειναι υποκλαση της PrivateCompartment, πρεπει να δουλεψει και εκει
για να ειναι ready_check.

Για την κλαση PlaneComponent:
Υποκλαση της Object.
Οι συναρτησεις PlaneComponent::process ειναι δηλωμενες οπως και οι παραπανω συναρτησης της κλασης Employee.
Η PlaneComponent::equal καλει πρωτα την equal της υπερκλασης της και μετα επιστρεφει την τιμη.
Η PlaneComponent::toString συγχωνευει την περιγραφη της υπερκλασης της με την δικια της περιγραφη και την επιστρεφει.
Οι συναρτησεις clone και ready_check ειναι pure virtual γιατι οι υποκλασεις αυτης της κλασης κανουν οτι χρειαζεται και
για αυτη την κλαση.

Για τις υποκλασεις της PlaneComponent για να ελεγχουμε αν οι εργατες εχουν δουλεψει στον συγγεκριμενο χωρο υπαρχουν καποιες
boolean μεταβλητες οι οποιες αρχικοποιουνται κατα τον constructor καθε κλασης και αλλαζουν κατα την κληση της process με ορισμα
τον συγγεκριμενο εργαζομενο.

Για την κλαση PassengerCompartment:
υποκλαση της PlaneComponent, εχει ενα Sub_PassCompartment το οποιο εχει 1/4 πιθανοτητα να δημιουργηθει, αν δημιουργηθει, εχει Και
αυτο 1/4 πιθανοτητες να δημιουργηθει ενα Sub_PassengerCompartment του Sub_PassCompartment.
Υπαρχει και δευτερος constructor στην κλαση αυτη, ο οποιος χρησιμοποιειται στην clone για να δημιουργηθει ενα PassengerCompartment
με σιγουργια οτι δεν θα δημιουργηθει κανενα Sub_PassCompartment αυτου.
Οι PassengerCompartment::process βαζουν τον εργατη να δουλεψει και στον υποχωρο της, αν υπαρχουν. Καλει επισης και την report
για τον υποχωρο. Τελος αλλαζει την boolean μεταβλητη που της αρμοζει.
Η PassengerCompartment::equal καλει πρωτα την equal της υπερκλασης της και μετα ελεγχει για τις δικες της τιμες. Τελος καλει και την
equal για τον υποχωρο αν αυτος υπαρχει και επιστρεφει την καταληλη boolean τιμη.
Η PassengerCompartment::clone αντιγραφει τις τιμες απο την this και αντιγραφει και τους υποχωρους αν αυτοι υπαρχουν.
Η PassengerCompartment::ready_check ελεγχει αν οι εργατες εχουν δουλεψει στον χωρο αυτο, εκτυπωνει αντιστοιχο μηνυμα και την
περιγραφη του χωρου και τελος ελεγχει αν και ο υποχωρος αν αυτος υπαρχει ειναι ready.
Η PassengerCompartment::toString() συγχωνευει την περιγραφη της υπερκλασης της και την δικια της περιγραφη, αυτη η περιγραφη συμπεριλαμβανει
και το ποιοι εργατες εχουν δουλεψει στον χωρο και την περιγραφη των υποχωρων αν αυτοι υπαρχουν.

Για την κλαση PrivateCompartment:
Υποκλαση της PlaneComponent, ειναι μια abstruct κλαση στην οποια οι υποκλασεις της πρεπει να δουλεψουν και σε αυτη για να ειναι ready.
Αντιστοιχα οι συναρτησεις της ειναι παρομοιες με τις συναρτησεις παραπανω και η clone ειναι pure virtual γιατι οι υποκλασεις της μπορουν
να αντιγραψουν τις protected private μεταβλητες της κλασης αυτης.

Για την κλαση EquipmentCompartment:
υποκλαση της PrivateCompartment.
οι EquipmentCompartment::process αν χρειαζεται καλουν και τις process της υπερκλασης τους.
Η EquipmentCompartment::process(CleaningEmployee) δεν χρειαζεται για την συγγεκριμενη κλαση αλλα χρειαζεται για την PrivateCompartment
Η EquipmentCompartment::equal ελεγχει πρωτα για την υπερκλαση αυτης
Η EquipmentCompartment::clone αντιγραφει επισης και τις τιμες της υπερκλασης της
Η EquipmentCompartment::ready_check ελεγχει πρωτα αν ειναι ready η υπερκλαση της και μετα για τις δικες της τιμες.
Η EquipmentCompartment::toString συγχωνευει την περιγραφη της υπερκλασης της με την δικια της, προσθετει αν εχουν δουλεψει οι εργαζομενοι ή οχι

Για την κλαση CargoBay:
υποκλαση της PrivateCompartment, εχει και ενα EquipmentCompartment
οι CargoBay::process αν χρειαζεται καλουν και τις process της υπερκλασης τους και τις process του equipment_space.
Η CargoBay::equal ελεγχει πρωτα για την υπερκλαση αυτης επισης καλει την equal για το equipment_space.
Η CargoBay::toString συγχωνευει την περιγραφη της υπερκλασης της με την δικια της, προσθετει αν εχουν δουλεψει οι εργαζομενοι ή οχι Και
προσθετει και την περιγραφη του equipment_space.
Η CargoBay::ready_check ελεγχει πρωτα αν ειναι ready η υπερκλαση της, μετα αν ειναι ready ο equipment_space και μετα για τις δικες της τιμες.
Η CargoBay::clone αντιγραφει επισης και τις τιμες της υπερκλασης της και καλει την clone για την equipment_space.

Για την κλαση Plane:
υποκλαση της Object, εχει δυο constructor, εναν για το κανονικο ο οποιος αρχικοποιει τα μελη του Plane και εναν που χρησιμοποιειται στην
Plane::clone, δηλαδη ενα κενο αντικειμενο χωρις αρχικοποιηση.
Στον πρωτο constructor υπαρχει και η υλοποιηση για το ποσα PassengerCompartment χρειαζονται στο αεροπλανο. Αυτο ειναι αναλογα με το πληθος των
επιβατων, καθε PassengerCompartment(ανεξαρτιτος αν εχει sub ή οχι) μπορει να χωρεσει εως και 75 ατομα, γιαυτο αναλογα αν χρειαζονται ή οχι φτιαχνει
και παραπανω απο 1 PassengerCompartment στον array pl_PassComp.
Το εξτρα μελος του class Plane, το size_PassComp ειναι μια μεταβλητη η οποια καθοριζει το ποσα PassengerCompartment υπαρχουν στον πινακα pl_PassComp
Οι Plane::process ελεγχουν τα μελη του Plane ειναι ready ή οχι, αν οχι βαζει τον εργαζομενο να δουλεψει εκει και καλει την report. Οταν τελειωσει απο το
καθε μερος συνεχιζει στο επομενο.
Για την Plane::process(CleaningEmployee), ο εργαζομενος δουλευει και στις EquipmentCompartment ωστε να ειναι ready απο το κομματι του PrivateCompartment.
Η Plane::equal ελεγχει αν ειναι equal τα μελη του καλωντας επισης και τις equal των κλασεων αν χρειαζεται και τελος καλει και την equal της υπερκλασης της.
Η Plane::ready_check ελεγχει αν ειναι ready τα μελη του αεροπλανου και αν ναι τοτε επιστρεφει την καταληλη boolean τιμη.
Η Plane::toString συγχωνευει τις περιγραφες της υπερκλασης της Plane, των μελων της και την δικια της περιγραφη και την επιστρεφει.
Η Plane::clone αντιγραφει με την χρηση της συναρτησης ::clone για καθε κλαση που χρειαζεται και αντιγραφει και τα δεομενα του αεροπλανου.

Η συναρτηση clone_encrypt_and_print, περνει ως ορισμα μια αναφορα σε Object και την αντιγραφει σε μια temp μεταβλητη.
Μετα ελεγχει αν ειναι ισα και επιστρεφει το καταληλο μηνυμα.
Φτιαχνει αλλες δυο tempSTR με τις περιγραφες τους.
Για το κομματι της encrypt:
βρησκει πρωτα μια τυχαια τιμη αναμεσα στο 0 και στο μεγηστο πληθος χαρακτηρων της περιγραφης της temp για το ποσοι χαρακτηρες θα αλλαξουν
Μεσα στην for η οποια εχει επαναληψεις οσες και οι χαρακτηρες που θα αλλαξουν
διαλεγει τυχαια ποιον χαρακτηρα να αλλαξει και διαλεγει τυχαια σε ποιον χαρακτηρα να μετατραπει και καλει την συναρτηση String::updateAt
και μετατρεπει τον χαρακτηρα.

επειτα εκτυπωνει την αλαγμενη περιγραφη και την παλια περιγραφη, τις συνενονει, εκτυπωνει το μηκος της μετα την εννοση.
Εκτυπωνει τον μεσαιο χαρακτηρα ή τους μεσαιους χαρακτηρες αναλογα αν ειναι μονο ή ζυγο το πληθος των χαρακτηρων μετα την συνενωση
κανει clear και εκτυπωνει το length της.

Output specifications:
Για οταν ειναι να δουλεψουν οι Εργατες και εχουν υποχωρους:
I SecurityEmployee, started working into a Cargo Bay //Workon απο την Plane::process για την CargoBay
Equipment_space of CargoBay: I SecurityEmployee, started working into a Equipment Compartment //workOn απο την CargoBay::workOn για την EquipmentCompartment
SecurityEmployee keep working on EquipmentCompartment//report απο την CargoBay::workOn για την EquipmentCompartment
SecurityEmployee keep working on CargoBay//report απο την Plane::process για την CargoBay

I SecurityEmployee, started working into a Passenger Compartment//workOn απο την Plane::process για την PassengerCompartment
{Sub PassengerCompartment: I SecurityEmployee, started working into a Passenger Compartment //workOn απο την PassengerCompartment::workOn
SecurityEmployee keep working on PassengerCompartment
}
SecurityEmployee keep working on PassengerCompartment
