#ifndef ORGAN_HPP
#define ORGAN_HPP
#include "Tissue.hpp"
#include"BST.hpp"

class Organ
{
public:
	Organ();
	~Organ();
	BST *trees;
	Tissue* TissueInOrgan;
	void InitializeTissue(Tissue*); 
};
#endif // !ORGAN_HPP
