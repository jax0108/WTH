#ifndef UUID2254426758064
#define UUID2254426758064

/**
  * RandomForestClassifier(base_estimator=deprecated, bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=10, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=5, n_jobs=None, num_outputs=3, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[3] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 3; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "background";
                    
                        case 1:
                            return "bad";
                    
                        case 2:
                            return "healthy";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[47] <= 0.09653407335281372) {
                            
                                
                        if (x[63] <= 0.40212708711624146) {
                            
                                
                        if (x[8] <= 0.00865714205428958) {
                            
                                
                        if (x[27] <= 0.019374553114175797) {
                            
                                
                        if (x[28] <= 0.029168511740863323) {
                            
                                
                        if (x[23] <= 0.1203799657523632) {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[131] <= 0.22786315577104688) {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[76] <= 0.49055033922195435) {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[9] <= 0.23944717645645142) {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[26] <= 0.46440884470939636) {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[9] <= 0.2573328763246536) {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[76] <= 0.18530413508415222) {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[10] <= 0.31352853775024414) {
                            
                                
                        if (x[26] <= 0.6270188689231873) {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[87] <= 0.8084122836589813) {
                            
                                
                        if (x[51] <= 0.1115727610886097) {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[14] <= 0.017503334674984217) {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[47] <= 0.10422850400209427) {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 575.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[19] <= 0.11259164288640022) {
                            
                                
                        if (x[70] <= 0.018026566598564386) {
                            
                                
                        if (x[134] <= 0.21334906667470932) {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 517.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 95.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[22] <= 0.07751796394586563) {
                            
                                
                        if (x[30] <= 0.013709144666790962) {
                            
                                
                        if (x[23] <= 0.11358683183789253) {
                            
                                
                        if (x[28] <= 0.1175934225320816) {
                            
                                
                        if (x[19] <= 0.28001342713832855) {
                            
                                
                        if (x[89] <= 0.9987822473049164) {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[124] <= 0.20670795813202858) {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[76] <= 0.04116995260119438) {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[23] <= 0.08106211945414543) {
                            
                                
                        if (x[7] <= 0.05603598617017269) {
                            
                                
                        if (x[96] <= 0.10323762707412243) {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[133] <= 0.7227447032928467) {
                            
                                
                        if (x[115] <= 0.7301755249500275) {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[11] <= 0.3854191303253174) {
                            
                                
                        if (x[124] <= 0.9835288226604462) {
                            
                                
                        if (x[25] <= 0.9968720078468323) {
                            
                                
                        if (x[19] <= 0.09279190748929977) {
                            
                                
                        if (x[24] <= 0.014867320191115141) {
                            
                                
                        if (x[90] <= 0.07567514851689339) {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[87] <= 0.3806157410144806) {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[115] <= 0.14720604568719864) {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[76] <= 0.008632110431790352) {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[51] <= 0.020218542777001858) {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 588.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[99] <= 0.2762310802936554) {
                            
                                
                        *classIdx = 2;
                        *classScore = 492.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 107.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] <= 0.20750334858894348) {
                            
                                
                        if (x[2] <= 0.24461358785629272) {
                            
                                
                        if (x[9] <= 0.29758088290691376) {
                            
                                
                        *classIdx = 1;
                        *classScore = 595.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[28] <= 0.011661726981401443) {
                            
                                
                        *classIdx = 0;
                        *classScore = 97.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[77] <= 0.055174896493554115) {
                            
                                
                        *classIdx = 0;
                        *classScore = 97.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[0] <= 0.062069641426205635) {
                            
                                
                        *classIdx = 1;
                        *classScore = 595.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[71] <= 0.25253552198410034) {
                            
                                
                        if (x[80] <= 0.6920894384384155) {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 97.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[66] <= 0.33590105175971985) {
                            
                                
                        if (x[18] <= 0.0427990835160017) {
                            
                                
                        if (x[80] <= 0.9012055993080139) {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 97.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] <= 0.1494964361190796) {
                            
                                
                        *classIdx = 1;
                        *classScore = 595.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[87] <= 0.051305204164236784) {
                            
                                
                        *classIdx = 0;
                        *classScore = 97.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[24] <= 0.20272597670555115) {
                            
                                
                        *classIdx = 1;
                        *classScore = 595.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 495.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[23] <= 0.07952168583869934) {
                            
                                
                        if (x[8] <= 0.02939064335078001) {
                            
                                
                        if (x[7] <= 0.05148434638977051) {
                            
                                
                        if (x[12] <= 0.1316920891404152) {
                            
                                
                        if (x[22] <= 0.1038639135658741) {
                            
                                
                        if (x[21] <= 0.3098929338157177) {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[74] <= 0.024598725140094757) {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[115] <= 0.3643976002931595) {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[121] <= 0.17329613864421844) {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[7] <= 0.02605999168008566) {
                            
                                
                        if (x[12] <= 0.012170164845883846) {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[111] <= 0.03436446748673916) {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[109] <= 0.19659271836280823) {
                            
                                
                        if (x[82] <= 0.01877354271709919) {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[87] <= 0.00297784642316401) {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[130] <= 0.01722104661166668) {
                            
                                
                        if (x[86] <= 0.034734456799924374) {
                            
                                
                        if (x[28] <= 0.019532330334186554) {
                            
                                
                        *classIdx = 0;
                        *classScore = 98.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[123] <= 0.421631321310997) {
                            
                                
                        if (x[110] <= 0.42121621966362) {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[92] <= 0.05080497823655605) {
                            
                                
                        if (x[10] <= 0.22910618782043457) {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[78] <= 0.8488736152648926) {
                            
                                
                        if (x[48] <= 0.1319887563586235) {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[121] <= 0.3284846618771553) {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[93] <= 0.055710576474666595) {
                            
                                
                        *classIdx = 1;
                        *classScore = 606.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 483.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] <= 0.027365274727344513) {
                            
                                
                        if (x[9] <= 0.3261513262987137) {
                            
                                
                        if (x[5] <= 0.001325898920185864) {
                            
                                
                        if (x[21] <= 0.1626983880996704) {
                            
                                
                        *classIdx = 1;
                        *classScore = 598.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 91.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[7] <= 0.054468948394060135) {
                            
                                
                        if (x[22] <= 0.1493932269513607) {
                            
                                
                        *classIdx = 1;
                        *classScore = 598.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 91.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[15] <= 0.007978096604347229) {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 598.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[133] <= 0.3411288559436798) {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[16] <= 0.004922178573906422) {
                            
                                
                        *classIdx = 0;
                        *classScore = 91.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[86] <= 0.024677995592355728) {
                            
                                
                        if (x[80] <= 0.8338673114776611) {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 91.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[24] <= 0.04530124366283417) {
                            
                                
                        if (x[9] <= 0.2732948511838913) {
                            
                                
                        *classIdx = 1;
                        *classScore = 598.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 498.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        


            
};



static RandomForestClassifier classifier;


#endif