/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:03:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/04 11:53:35 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const AAnimal *meta[100];
    int           i=0;

    while (i < 50)
    {
        meta[i] = new Cat();
        if (!meta[i])
        {
            std::cout << "Something went wrong with Cat's allocation." << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    while (i < 100)
    {
        meta[i] = new Dog();
        if (!meta[i])
        {
            std::cout << "Something went wrong with Dog's allocation." << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i=0;
    while (i < 100)
    {
        std::cout << "AAnimal type: " << meta[i]->getType() << std::endl;
        meta[i]->makeSound();
        i++;
    }
    i=0;
    while (i < 100)
    {
        delete meta[i];
        i++;
    }
    Cat *c = new Cat();
    if (!c)
    {
        std::cout << "Something went wrong with Cat's allocation." << std::endl;
        exit(EXIT_FAILURE);
    }
    c->setIdea(0, "Let's scratch that sofa!!");
    c->setIdea(1, "Give me fresh water.");
    c->setIdea(2, "Can I have a cat friend?");
    c->setIdea(3, "Feed me!!");
    c->setIdea(4, "Hello hooman, where is my treat?");
    c->setIdea(5, "Wake up, time to eat.");
    c->setIdea(6, "Why are you still sleeping?");
    c->setIdea(7, "I need more toys!!");
    c->setIdea(8, "Let's push that glass of water!");
    c->setIdea(9, "I should find out how many cats does the neighborhood has!!");
    c->setIdea(10, "Let's_scratch_that_sofa!!");
    c->setIdea(11,"Give_me_fresh_water.");
    c->setIdea(12,"Can_I_have_a_cat_friend?");
    c->setIdea(13,"Feed_me!!");
    c->setIdea(14,"Hello_hooman,_where_is_my_treat?");
    c->setIdea(15,"Wake_up,_time_to_eat.");
    c->setIdea(16,"Why_are_you_still_sleeping?");
    c->setIdea(17,"I_need_more_toys!!");
    c->setIdea(18,"Let's_push_that_glass_of_water!");
    c->setIdea(19,"I_should_find_out_how_many_cats_does_the_neighborhood_has!!");
    c->setIdea(20, "Let's*scratch*that*sofa!!");
    c->setIdea(21,"Give*me*fresh*water.");
    c->setIdea(22,"Can*I*have*a*cat*friend?");
    c->setIdea(23,"Feed*me!!");
    c->setIdea(24,"Hello*hooman,*where*is*my*treat?");
    c->setIdea(25,"Wake*up,*time*to*eat.");
    c->setIdea(26,"Why*are*you*still*sleeping?");
    c->setIdea(27,"I*need*more*toys!!");
    c->setIdea(28,"Let's*push*that*glass*of*water!");
    c->setIdea(29,"I*should*find*out*how*many*cats*does*the*neighborhood*has!!");
    c->setIdea(30, "Let's#scratch#that#sofa!!");
    c->setIdea(31,"Give#me#fresh#water.");
    c->setIdea(32,"Can#I#have#a#cat#friend?");
    c->setIdea(33,"Feed#me!!");
    c->setIdea(34,"Hello#hooman,#where#is#my#treat?");
    c->setIdea(35,"Wake#up,#time#to#eat.");
    c->setIdea(36,"Why#are#you#still#sleeping?");
    c->setIdea(37,"I#need#more#toys!!");
    c->setIdea(38,"Let's#push#that#glass#of#water!");
    c->setIdea(39,"I#should#find#out#how#many#cats#does#the#neighborhood#has!!");
    c->setIdea(40, "Let's~scratch~that~sofa!!");
    c->setIdea(41,"Give~me~fresh~water.");
    c->setIdea(42,"Can~I~have~a~cat~friend?");
    c->setIdea(43,"Feed~me!!");
    c->setIdea(44,"Hello~hooman,~where~is~my~treat?");
    c->setIdea(45,"Wake~up,~time~to~eat.");
    c->setIdea(46,"Why~are~you~still~sleeping?");
    c->setIdea(47,"I~need~more~toys!!");
    c->setIdea(48,"Let's~push~that~glass~of~water!");
    c->setIdea(49,"I~should~find~out~how~many~cats~does~the~neighborhood~has!!");
    c->setIdea(50, "Let's:scratch:that:sofa!!");
    c->setIdea(51, "Give:me:fresh:water.");
    c->setIdea(52, "Can:I:have:a:cat:friend?");
    c->setIdea(53, "Feed:me!!");
    c->setIdea(54, "Hello:hooman, where:is:my:treat?");
    c->setIdea(55, "Wake:up, time:to:eat.");
    c->setIdea(56, "Why:are:you:still:sleeping?");
    c->setIdea(57, "I:need:more:toys!!");
    c->setIdea(58, "Let's:push:that:glass:of:water!");
    c->setIdea(59, "I:should:find:out:how:many:cats:does:the:neighborhood:has!!");
    c->setIdea(60, "...Let's scratch that sofa!!");
    c->setIdea(61, "...Give me fresh water.");
    c->setIdea(62, "...Can I have a cat friend?");
    c->setIdea(63, "...Feed me!!");
    c->setIdea(64, "...Hello hooman, where is my treat?");
    c->setIdea(65, "...Wake up, time to eat.");
    c->setIdea(66, "...Why are you still sleeping?");
    c->setIdea(67, "...I need more toys!!");
    c->setIdea(68, "...Let's push that glass of water!");
    c->setIdea(69, "...I should find out how many cats does the neighborhood has!!");
    c->setIdea(70, ",,,Let's scratch that sofa!!");
    c->setIdea(71, ",,,Give me fresh water.");
    c->setIdea(72, ",,,Can I have a cat friend?");
    c->setIdea(73, ",,,Feed me!!");
    c->setIdea(74, ",,,Hello hooman, where is my treat?");
    c->setIdea(75, ",,,Wake up, time to eat.");
    c->setIdea(76, ",,,Why are you still sleeping?");
    c->setIdea(77, ",,,I need more toys!!");
    c->setIdea(78, ",,,Let's push that glass of water!");
    c->setIdea(79, ",,,I should find out how many cats does the neighborhood has!!");
    c->setIdea(80, ",Let's scratch that sofa!!");
    c->setIdea(81, ",Give me fresh water.");
    c->setIdea(82, ",Can I have a cat friend?");
    c->setIdea(83, ",Feed me!!");
    c->setIdea(84, ",Hello hooman, where is my treat?");
    c->setIdea(85, ",Wake up, time to eat.");
    c->setIdea(86, ",Why are you still sleeping?");
    c->setIdea(87, ",I need more toys!!");
    c->setIdea(88, ",Let's push that glass of water!");
    c->setIdea(89, ",I should find out how many cats does the neighborhood has!!");
    c->setIdea(90, ".Let's scratch that sofa!!");
    c->setIdea(91, ".Give me fresh water.");
    c->setIdea(92, ".Can I have a cat friend?");
    c->setIdea(93, ".Feed me!!");
    c->setIdea(94, ".Hello hooman, where is my treat?");
    c->setIdea(95, ".Wake up, time to eat.");
    c->setIdea(96, ".Why are you still sleeping?");
    c->setIdea(97, ".I need more toys!!");
    c->setIdea(98, ".Let's push that glass of water!");
    c->setIdea(99, ".I should find out how many cats does the neighborhood has!!");
    Cat *d = new Cat(*c);
    if (!d)
    {
        std::cout << "Something went wrong with Cat's allocation." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "The " << c->getType() << " has these ideas: " << std::endl;
    c->getIdeas();
    delete(c);
    std::cout << "The " << d->getType() << " has these ideas: " << std::endl;
    d->getIdeas();
    delete(d);
    return (0);
}