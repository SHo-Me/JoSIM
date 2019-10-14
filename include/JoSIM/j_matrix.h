// Copyright (c) 2019 Johannes Delport
// This code is licensed under MIT license (see LICENSE for details)
#ifndef JOSIM_J_MATRIX_H
#define JOSIM_J_MATRIX_H
#include "./AnalysisType.hpp"
#include "j_components.h"
#include "./Input.hpp"
#include "./Errors.hpp"

#include <unordered_map>

class matrix_element {
public:
  std::string label;
  int rowIndex;
  int colIndex;
  double value;
  matrix_element() {
    label = "NOTHING";
    rowIndex = -1;
    colIndex = -1;
    value = 0.0;
  }
};

struct RowDescriptor {
  enum class Type {
    VoltageNode,
    PhaseNode,
    VoltageResistor,
    PhaseResistor,
    VoltageCapacitor,
    PhaseCapacitor,
    VoltageInductor,
    PhaseInductor,
    VoltageJJ,
    PhaseJJ,
    VoltageVS,
    PhaseVS,
    VoltageCS,
    PhaseCS,
    VoltagePS,
    PhasePS,
    VoltageTX,
    VoltageTX1,
    VoltageTX2,
    PhaseTX,
    PhaseTX1,
    PhaseTX2
  } type;
  int index;

  RowDescriptor() {}
};

struct LabelNodes {
  std::string posNode;
  std::string negNode;
};

class Matrix {
public:
  JoSIM::AnalysisType analysisType;
  Components components;
  std::vector<NodeConnections> nodeConnections;
  std::vector<RowDescriptor> rowDesc;
  std::unordered_map<std::string, RowDescriptor> deviceLabelIndex;
  std::unordered_map<std::string, int> nodeMap, relToXMap;
  std::vector<matrix_element> mElements;
  std::vector<std::vector<double>> sources;
  std::vector<std::string> rowNames, columnNames, relevantToStore;
  std::vector<double> nzval;
  std::vector<int> colind, rowptr;
  std::vector<int> relXInd;
  std::unordered_map<int, int> XtoTraceMap;
  std::unordered_map<std::string, LabelNodes> labelNodes;
  int Nsize, Msize;

  Matrix(){};
  void create_matrix(Input &iObj);

  void create_A_volt(Input &iObj);

  void create_A_phase(Input &iObj);

  void create_CSR();

  void find_relevant_x(Input &iObj);
};
#endif
