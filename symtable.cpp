#include "symtable.h"

// construtor para a primeira tabela
SymTable::SymTable() : prev(nullptr)
{
}

// construtor para novas tabelas
SymTable::SymTable(SymTable * t) : prev(t)
{		
}

// insere um simbolo na tabela
bool SymTable::Insert(string s, Symbol symb) 
{ 							//Insert retorna uma dupla com uma string e um boleano
	//table[s] = symb;
	const auto& [pos, success] = table.insert({s,symb});
	return success;
}

// busca um simbolo na tabela atual 
// se nao encontrar, busca nas tabelas dos demais escopos
Symbol * SymTable::Find(string s) 
{
	for (SymTable * st = this; st != nullptr; st = st->prev) 
	{
        auto found = st->table.find(s);
        if (found != st->table.end()) //quando aponta para o fim da tabela e invalido
			return &found->second; //como preciso so do simbolo retorna o segundo
    }

    return nullptr;
} 

