#include "TableData.h"
using std::string;
using std::vector;

TableData::TableData() : table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>), rowsCount(0), columnsCount(0) {}
TableData::TableData(vector<vector<double>> &table, vector<string> &rowsNames, vector<string> &columnsNames) : rowsCount(rowsNames.size()), columnsCount(columnsNames.size())
{
    this->table = new auto(table);
    this->rowsNames = new auto(rowsNames);
    this->columnsNames = new auto(columnsNames);
}
u_int TableData::getRowCount() const
{
    return rowsCount;
}
u_int TableData::getColumnCount() const
{
    return columnsCount;
}
vector<vector<double>> *TableData::getTable() const
{
    return table;
}
vector<vector<double>> *TableData::getTable()
{
    return table;
}
void TableData::addRow(vector<double> &row, u_int index, const string &rowName)
{
    if (row.size() == columnsCount)
    {
        if (rowsCount > index)
        {
            rowsNames->insert(rowsNames->begin() + index, rowName);
            table->insert(table->begin() + index, row);
        }
        else if (rowsCount == index)
        {
            rowsNames->push_back(rowName);
            table->push_back(row);
        }
        rowsCount += 1;
    }
    else
        std::cout << "Add row out of range or overflow" << std::endl;
}
void TableData::addColumn( u_int index, const string columnName)
{
    vector<double> column(columnsCount,0);//default column
//    vector<double> column;
//    for(u_int i=0;i < columnsCount;++i ){
//        column.push_back(0);
//    }
    if (column.size() == columnsCount)
    {
        if (columnsCount > index)
        {
            for (u_int i = 0; rowsCount > i; ++i)
                (*table)[i].insert((*table)[i].begin() + index, column[i]);
            columnsNames->insert(columnsNames->begin() + index, columnName);
        }
        else if (columnsCount == index)
        {
            for (u_int i = 0; columnsCount > i; ++i)
                (*table)[i].push_back(column[i]);
            columnsNames->push_back(columnName);
        }
        columnsCount += 1;
    }
    else
        std::cout << "Add column out of range or overflow" << std::endl;

}
vector<string> *TableData::getRowsNames() const
{
    return rowsNames;
}
vector<string> *TableData::getColumnsNames() const
{
    return columnsNames;
}
void TableData::deleteColumn(const u_int index)
{
    if (columnsCount > index)
    {
        columnsNames->erase(columnsNames->begin() + index);
        for (u_int i = 0; rowsCount > i; ++i)
            (*table)[i].erase((*table)[i].begin() + index);
        columnsCount -= 1;
    }
    else
        std::cout << "Remove column out of range or overflow" << std::endl;
}
void TableData::deleteRow(const u_int index)
{
    if (rowsCount > index)
    {
        rowsNames->erase(rowsNames->begin() + index);
        table->erase(table->begin() + index);
        rowsCount -= 1;
    }
    else
        std::cout << "Remove row out of range or overflow" << std::endl;
}

void TableData::printTable() const
{
    std::cout << std::endl;
    std::cout << "Names:";
    std::cout << std::endl;
    for (auto c : *columnsNames)
    {
        std::cout << c << " ";
    }
    for (auto r : *rowsNames)
    {
        std::cout << r << " ";
        std::cout << std::endl;
    }
    std::cout << "Table:";
    std::cout << std::endl;
    for (auto data : *table)
    {
        for (auto d : data)
            std::cout << d << " ";
        std::cout << std::endl;
    }
    std::cout << "Size:";
    std::cout << std::endl;

    std::cout << "Columns:" << columnsCount << " ";
    std::cout << "Rows:" << rowsCount << " ";
    std::cout << std::endl;
}
void TableData::inizialize(){
    if (rowsCount == 0 && columnsCount == 0)
    {
        table->push_back(*new vector<double>{0});
        rowsNames->push_back("y");
         columnsNames->push_back("x");
        columnsCount += 1;
        rowsCount +=1;
    }
}
void TableData::loadModelRandom(const u_int columns, const u_int rows)
{
    for (u_int j = 0; columns > j; j++)
    {
        vector<double> d = vector<double>();
        for (u_int i = 0; rows > i; i++)
        {
            d.push_back(i + j);
        }
        columnsNames->push_back("");
        table->push_back(d);

    }
    for (u_int i = 0; rows > i; i++)
    {
        rowsNames->push_back("");
    }
    columnsCount = columns;
    rowsCount = rows;
    printTable();
}
