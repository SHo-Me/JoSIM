// Copyright (c) 2019 Johannes Delport
// This code is licensed under MIT license (see LICENSE for details)
#include "JoSIM/AnalysisType.hpp"
#include "JoSIM/j_matrix.h"
#include "JoSIM/j_output.h"
#include "JoSIM/j_parser.h"
#include "JoSIM/j_simulation.h"
#include "JoSIM/j_std_include.h"
#include "JoSIM/j_verbose.h"

#include "JoSIM/CliOptions.hpp"
#include "JoSIM/Input.hpp"


int main(int argc, const char **argv) {


  JoSIM::CliOptions::version_info();
  auto cli_options = JoSIM::CliOptions::parse(argc, argv);

  Input iObj(cli_options.analysis_type, 
             cli_options.input_type,
             cli_options.verbose);

  Matrix mObj;
  Simulation sObj;
  Output oObj;

  iObj.read_input_file(cli_options.cir_file_name, iObj.fileLines);
  iObj.split_netlist(iObj.fileLines, iObj.controls, iObj.parameters,
                     iObj.netlist);
  if (iObj.parameters.unparsedParams.size() > 0)
    Parser::parse_parameters(iObj.parameters);
  iObj.expand_subcircuits();
  iObj.expand_maindesign();
  if (iObj.argVerb)
    Verbose::print_expanded_netlist(iObj.expNetlist);
  sObj.identify_simulation(iObj.controls, iObj.transSim.prstep,
                           iObj.transSim.tstop, iObj.transSim.tstart,
                           iObj.transSim.maxtstep);
  mObj.find_relevant_x(iObj);
  mObj.create_matrix(iObj);
  if (cli_options.analysis_type == JoSIM::AnalysisType::Voltage)
    sObj.trans_sim<JoSIM::AnalysisType::Voltage>(iObj, mObj);
    //sObj.transient_voltage_simulation(iObj, mObj);
  else if (cli_options.analysis_type == JoSIM::AnalysisType::Phase)
    sObj.trans_sim<JoSIM::AnalysisType::Phase>(iObj, mObj);
    // sObj.transient_phase_simulation(iObj, mObj);
  oObj.relevant_traces(iObj, mObj, sObj);

  if (cli_options.output_to_file) {
    if (cli_options.output_file_type == JoSIM::FileOutputType::Csv)
      oObj.write_data(cli_options.output_file_name, mObj, sObj);
    else if (cli_options.output_file_type == JoSIM::FileOutputType::Dat)
      oObj.write_legacy_data(cli_options.output_file_name, mObj, sObj);
    else if (cli_options.output_file_type == JoSIM::FileOutputType::WrSpice)
      oObj.write_wr_data(cli_options.output_file_name);
  }
  if (!cli_options.output_to_file)
    oObj.write_cout(mObj, sObj);
  return 0;
}
