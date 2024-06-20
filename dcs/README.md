# C++
***(Modulo 03)***

## Index

01. **[inheritance introduction](#inheritance-introduction)**
02. **[inheritance in classes](#inheritance-in-classes)**
03. **["is a" test and "has a" test](#is-a-test-and-has-a-test)**
04. **[access specifier (base class & class members)](#access-specifier-base-class--class-members)**
05. **[multiple inheritance](#multiple-inheritance)**
06. **[The diamond problem](#the-diamond-problem)**
07. **[Resources](#resources)**

## Inheritance introduction
- ***(Introdução a herança)***: **Herança é o meio pelo qual você pode criar novas classes reutilizando e expandindo as definições de classe existentes**.
- A herança também é fundamental para tornar `polymorphism` (polimorfismo) possível, e o polimorfismo é uma característica básica da programação orientada a objetos.
- Uma classe é derivada de outra adicionando propriedades extras, por especialização e tornando a nova classe uma versão especializada da classe mais geral.

***Exemplo 1 Animal.hpp***
```cpp
// classe base
class Animal {
private:
	int _numberOfLegs;

public:
	Animal();
	Animal(Animal const &);
	Animal& operator=(Animal const &);
	~Animal();

	void run(int distance);
	void call();
	void eat(std::string const & what);
	void walk(int distance);
};

// Significa que Cat é um animal
// public inheritance (herança pública)
class Cat : public Animal {

public:
	Cat();
	Cat(Cat const &);
	Cat& operator=(Cat const &);
	~Cat();

	void scornSomeone(std::string const & target);

};

class Pony : public Animal {

public:
	Pony();
	Pony(Pony const &);
	Pony& operator=(Pony const &);
	~Pony();

	void doMagic(std::string const & target);
	void run(int distance); // Isto substituirá a função animal
};

```
[↑ Index ↑](#index)

## inheritance in classes
- *(herança em classes)* A `classe base` (base class) também é referido como a `superclass` de uma classe derivada dela e a `derived class` é a `subclass` de sua base.
- Uma classe derivada contém automaticamente todos os membros de dados de sua classe base e (com algumas restrições) todos os membros de função. Uma classe derivada herda os membros de dados e os membros de função de sua classe base.

***Exemplo de Classe base e Classe derivada***
[<img align="center" src="https://github.com/faleite/42cpp03/blob/main/dcs/derived_class.png" width="75%"/>](https://github.com/faleite/42cpp03/blob/main/dcs/derived_class.png)

[↑ Index ↑](#index)

## "is a" test and "has a" test
- `"é um" teste e "tem um" teste` Os objetos de classe derivada devem ser objetos de `especializações sensatas` da classe base. Isso significa que uma classe derivada deve definir um subconjunto dos objetos representados pela classe base.
- O "é um" teste é uma excelente primeira verificação, mas não é infalível. Se as classes falharem no teste "é um", é quase certo que você não deverá usar a derivação de classes. Neste caso, você pode verificar o "tem um" teste.
- Um objeto de classe passa no "tem um" teste se contiver uma instância de outra classe. Você pode acomodar isso incluindo um objeto na segunda classe como membro de dados da primeira. Por exemplo, um objeto `Automobile` (Automóvel) teria um objeto `Engine` (motor) como membro de dados. Esse tipo de relacionamento é chamado de `aggregation` (agregação).

[↑ Index ↑](#index)

## access specifier (base class & class members)
- Determina como os membros da classe base podem ser acessados ​​dentro da classe derivada
- `private`: os membros são totalmente privados da classe. Eles não apenas não podem ser acessados ​​de fora da classe base, mas também não podem ser acessados ​​de dentro de uma classe que os herda.
- `protected`: os membros de uma classe base são acessíveis de dentro da classe derivada, mas protegidos contra interferências externas.
- O acesso aos membros herdados de um objeto de classe derivada não é determinado apenas por sua especificação de acesso na classe base, mas pelo especificador de acesso na classe base e pelo especificador de acesso da classe base na classe derivada.

***Exemplo***
```cpp
// Exemplo de especificador de acesso para membros da classe
class Quadruped { // Can access name, run() and legs

private:
	std::string name; // Only accessible from an Quadruped object

protected:
	Leg legs[4]; // Accessible from an Quadruped or derived object

public:
	void run(); // Accessible from wherever
};
```
- Em geral, existem três possibilidades para o especificador de classe base: `public`, `protected`, `private`. Se você omitir o especificador de acesso base, o padrão será `private`
- Ser capaz de alterar o nível de acesso dos membros herdados em uma classe derivada oferece um certo grau de flexibilidade, mas lembre-se de que **você só pode tornar o nível de acesso mais rigoroso**, não pode relaxar o nível de acesso especificador na classe base.

***Efeito do especificador de classe base na acessibilidade de membros herdados***
[<img align="center" src="https://github.com/faleite/42cpp03/blob/main/dcs/access_specifier.png" width="75%"/>](https://github.com/faleite/42cpp03/blob/main/dcs/access_specifier.png)

- Em resumo, você precisa considerar dois aspectos ao definir uma hierarquia de classes: **os especificadores de acesso para os membros de cada classe e o especificador de acesso da classe base em cada classe derivada.**

[↑ Index ↑](#index)

## multiple inheritance
- Uma classe derivada pode ter quantas classes base diretas forem necessárias para um aplicativo. Isso é chamado de `multiple inheritance` oposto a `single inheritance`, em que uma única classe base é usada. A herança múltipla é usada com muito menos frequência do que a herança única e é melhor evitada tanto quanto possível.

***m exemplo de herança múltipla***
[<img align="center" src="https://github.com/faleite/42cpp03/blob/main/dcs/multiple_inheritance.png" width="75%"/>](https://github.com/faleite/42cpp03/blob/main/dcs/multiple_inheritance.png)


```cpp
class CerealPack : public Carton, public Contents
{
	// details of the class...
};
```

- A classe `CerealPack` herdará todos os membros de ambas as classes base, portanto incluirá os membros da base indireta, `Box`. Os construtores das classes herdadas são chamados na mesma ordem em que são herdados. Neste caso, o construtor `Carton` será chamado antes do construtor `Contents`.
- O nível de acesso de cada membro herdado é determinado por dois fatores: `o especificador de acesso do membro na classe base` e `o especificador de acesso da classe base`.

### Virtual base classes
- Para evitar a duplicação de uma classe base, você deve identificar ao compilador que a classe base deve aparecer apenas uma vez dentro de uma classe derivada. Você faz isso especificando a classe como `virtual base class` usando a palavra-chave `virtual`.

[↑ Index ↑](#index)

## The diamond problem
- O problema do diamante ocorre quando duas superclasses de uma classe possuem uma classe base comum. Por exemplo, no diagrama a seguir, a classe TA obtém duas cópias de todos os atributos da classe Person, o que causa ambiguidades.
- A solução para este problema é a palavra-chave `virtual`. Tornamos as classes `Faculty` e `Student` como classes base virtuais para evitar duas cópias de `Person` na classe `TA`.

***exemplo de herança múltipla***
[<img align="center" src="https://github.com/faleite/42cpp03/blob/main/dcs/diamond_problem.png" width="75%"/>](https://github.com/faleite/42cpp03/blob/main/dcs/diamond_problem.png)

- Como o virtual resolve o problema do diamante? Herança virtual significa que haverá apenas 1 instância da classe base A e não 2. [fonte](https://stackoverflow.com/questions/2659116/how-does-virtual-inheritance-solve-the-diamond-multiple-inheritance-ambiguit)

[<img align="center" src="https://github.com/faleite/42cpp03/blob/main/dcs/virtual.png" width="75%"/>](https://github.com/faleite/42cpp03/blob/main/dcs/virtual.png)

## Resources
- [Create UML class diagrams](https://www.drawio.com/blog/uml-class-diagrams)
- [Inheritance — Multiple and Virtual Inheritance](https://isocpp.org/wiki/faq/multiple-inheritance)

[↑ Index ↑](#index)