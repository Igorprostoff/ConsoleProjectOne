// ClassInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //в stdafx.h собраны файлы которые не перестраиваются каждый раз при перестройке приложения
#include "WeaponClass1.h"
#include "Launcher.h"

class assualt_rifle : public WeaponClass1 {
public:
	assualt_rifle() :WeaponClass1() {
		return;
	}
	double recoil;
};

class soldier {
public:
	soldier() {};
	int health;
	string name;
};

class combat_unit : public WeaponClass1, public soldier {
public:
	combat_unit() {

	}
};


int main()
{//синтаксис :
	/* класс имя_нового класса : [тип наследования] имя_родительского_класса1,
		                      [тип наследования] имя родительского класса2

		Доступность свойств и методов базового класса внутри производного класса,
		даже если они не обявлены в производном */
	assualt_rifle obj1;
	obj1.play_animation();	//public методы и св-ва заимствуются из базового класса

	combat_unit obj2;
	obj2.health = 15; // доступны члены одного родительсокго класса
	obj2.load();
	getchar();
	//у дочернего класса нескольких родителей доступны все их св-ва и методы



	// ___________________________________| private  | protected | public |
	// Доступ из тела класса              | открыт   | открыт    | открыт |
	//Доступ из производных классов       | закрыт   | открыт    | открыт |
	//Доступ из внешних функций и классов |	закрыт	 | закрыт    | открыт |



	/*Базовый класс   Режим наследования   | Производный класс
		private     |   public             | недоступен
		protected   | ----------->         | protected
		public      |                      | public
		____________|______________________|__________________
		private     |   protected          | Недоступен
		protected   | ----------->         | protected
  		public      |                      | protected
		____________|______________________|__________________
		private     |  private             | Недоступен
		protected   | ----------->         | private
		public      |                      | private*/



    return 0;
}

