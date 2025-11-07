/* -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
 vi: set ts=2 noet:

(c) Copyright Rosetta Commons Member Institutions.
(c) This file is part of the Rosetta software suite and is made available under license.
(c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
(c) For more information, see http://www.rosettacommons.org. Questions about this can be
(c) addressed to University of Washington CoMotion, email: license@uw.edu.

@file apps/pilot/mhassan/bootcamp_jd2.cc
@brief A test mover
@author mohassan-glitch (mosavverul.hassan@Vanderbilt.edu) */

/* devel headers */
#include <devel/init.hh>
/* option headers */
#include<basic/options/option.hh>
/* protocol headers */
#include <protocols/jd2/JobDistributor.hh>
//#include <protocols/bootcamp/BootcampMover.hh>

/* utility headers */
#include <utility/excn/Exceptions.hh>

/* basic headers */
#include <basic/Tracer.hh>
#include <basic/options/keys/in.OptionKeys.gen.hh>
#include <basic/options/option.hh>
#include <basic/options/keys/OptionKeys.hh>
#include <utility/options/OptionCollection.hh>
#include <basic/options/option_macros.hh>
#include <utility/pointer/owning_ptr.hh>
/* Core Headers*/
#include <core/pose/Pose.hh>              // For PoseOP type
#include <core/import_pose/import_pose.hh> // For pose_from_file function
#include <core/scoring/ScoreFunctionFactory.hh>
#include <core/scoring/ScoreFunction.hh>

static basic::Tracer TR("bootcamp_jd2");

/// @brief Indicate which commandline flags are relevant to this application.
void register_options() {
	using namespace basic::options;
	using namespace basic::options::OptionKeys;

	option.add_relevant( in::file::s );
	option.add_relevant( in::file::l );

}
/* @brief Program entry point. */
int main( int argc, char ** argv ) {

                /// @brief Program entry point.
	try {
		using namespace basic::options;
		using namespace basic::options::OptionKeys;
		using namespace core::scoring;


		//this won't compile until you fill in brief and default yourself

		register_options();
		devel::init( argc, argv );
	        utility::vector1< std::string > filenames = basic::options::option[ basic::options::OptionKeys::in::file::s ].value();

	        if ( filenames.size() > 0 ) {

		    std::cout << "You entered: " << filenames[ 1 ] << " as the PDB file to be read" << std::endl;
                    /* Loading the protein structure into  a pose object */
                    
                    core::pose::PoseOP mypose = core::import_pose::pose_from_file( filenames [ 1 ] );

                    core::scoring::ScoreFunctionOP sfxn = core::scoring::get_score_function();

                    core::Real score = sfxn->score( *mypose );

                    std::cout<< "Pose Score: " << score << std::endl;

	        }
	        else {

		    std::cout << "You didn’t provide a PDB file with the -in::file::s option" << std::endl;
		
                    return 1;
	        }

		//protocols::bootcamp::BootcampMoverOP mover_protocol( new protocols::bootcamp::BootcampMover() );

		//protocols::jd2::JobDistributor::get_instance()->go( mover_protocol );


	} catch ( utility::excn::Exception const & e ) {
		e.display();
		return -1;
	}
	return 0;
}
