import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: human_skin_001_material
        objectName: "human_skin.001"
        baseColor: "#fff0aa5d"
        roughness: 0.5
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: cornea_001_material
        objectName: "cornea.001"
        baseColor: "#ffcccccc"
        roughness: 0.5
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: human_eyes_001_material
        objectName: "human_eyes.001"
        baseColor: "#ffcccccc"
        roughness: 0.5
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: fur_001_material
        objectName: "Fur.001"
        baseColor: "#ffcccccc"
        roughness: 0.5
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: teeth_001_material
        objectName: "Teeth.001"
        baseColor: "#ffcccccc"
        roughness: 0.5
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    Skin {
        id: skin        
        joints: [
            root,
            pelvis,
            thigh_R,
            calf_R,
            foot_R,
            toes_R,
            thigh_L,
            calf_L,
            foot_L,
            toes_L,
            spine01,
            spine02,
            spine03,
            clavicle_L,
            upperarm_L,
            lowerarm_L,
            hand_L,
            thumb01_L,
            thumb02_L,
            thumb03_L,
            index00_L,
            index01_L,
            index02_L,
            index03_L,
            middle00_L,
            middle01_L,
            middle02_L,
            middle03_L,
            ring00_L,
            ring01_L,
            ring02_L,
            ring03_L,
            pinky00_L,
            pinky01_L,
            pinky02_L,
            pinky03_L,
            clavicle_R,
            upperarm_R,
            lowerarm_R,
            hand_R,
            thumb01_R,
            thumb02_R,
            thumb03_R,
            index00_R,
            index01_R,
            index02_R,
            index03_R,
            middle00_R,
            middle01_R,
            middle02_R,
            middle03_R,
            ring00_R,
            ring01_R,
            ring02_R,
            ring03_R,
            pinky00_R,
            pinky01_R,
            pinky02_R,
            pinky03_R,
            neck,
            head
        ]
        inverseBindPoses: [
            Qt.matrix4x4(1, -2.48528e-06, -4.42732e-07, 1.32501e-07, 6.99244e-09, -0.172653, 0.984983, 0.0269238, -2.52442e-06, -0.984989, -0.172653, 0.0500546, 0, 0, 0, 1),
            Qt.matrix4x4(1, 1.15025e-07, 3.08164e-07, -1.04632e-07, -8.75871e-09, 0.945882, -0.324528, -0.798063, -3.28799e-07, 0.324531, 0.945876, -0.296874, 0, 0, 0, 1),
            Qt.matrix4x4(-0.995978, 0.089554, -0.00267533, -0.198576, -0.0895651, -0.995977, 0.00466665, 0.917592, -0.00224565, 0.00488938, 0.999984, -0.0156042, 0, 0, 0, 1),
            Qt.matrix4x4(-0.994213, 0.0988542, -0.0420573, -0.202425, -0.0982533, -0.995038, -0.0161117, 0.48006, -0.0434401, -0.0118845, 0.998984, -0.0136179, 0, 0, 0, 1),
            Qt.matrix4x4(-0.998137, 0.0358268, -0.0493809, -0.196585, -0.0605846, -0.486949, 0.871326, 0.0332742, 0.00717111, 0.872703, 0.48821, -0.0924862, 0, 0, 0, 1),
            Qt.matrix4x4(0.989136, -0.0660168, 0.131343, 0.182786, -0.137607, -0.10156, 0.985264, -0.177507, -0.0517044, -0.992643, -0.109543, 0.0277102, 0, 0, 0, 1),
            Qt.matrix4x4(-0.995978, -0.089554, 0.00267533, 0.198576, 0.089565, -0.995976, 0.0046667, 0.917591, 0.00224575, 0.00488939, 0.999984, -0.0156042, 0, 0, 0, 1),
            Qt.matrix4x4(-0.994213, -0.0988542, 0.0420573, 0.202425, 0.0982533, -0.995037, -0.0161117, 0.48006, 0.0434402, -0.0118845, 0.998984, -0.0136179, 0, 0, 0, 1),
            Qt.matrix4x4(-0.998137, -0.0358268, 0.0493809, 0.196585, 0.0605847, -0.486949, 0.871326, 0.0332741, -0.00717108, 0.872703, 0.48821, -0.0924862, 0, 0, 0, 1),
            Qt.matrix4x4(-0.986126, -0.107284, 0.126669, 0.183781, 0.137607, -0.101561, 0.985265, -0.177507, -0.0928384, 0.989034, 0.114916, -0.0200766, 0, 0, 0, 1),
            Qt.matrix4x4(1, -1.24939e-07, 4.57e-07, 1.44987e-07, 5.45055e-08, 0.988531, 0.151061, -1.00118, -4.70631e-07, -0.15106, 0.988525, 0.188895, 0, 0, 0, 1),
            Qt.matrix4x4(1, 1.13347e-07, 2.33752e-07, -1.28697e-07, -9.00769e-08, 0.99528, -0.0971074, -1.12794, -2.43648e-07, 0.0971094, 0.995274, -0.0917911, 0, 0, 0, 1),
            Qt.matrix4x4(1, -8.71945e-09, 3.98059e-07, 2.80884e-08, 1.18002e-08, 0.999977, -0.00765202, -1.24525, -3.97978e-07, 0.00765337, 0.999971, 0.0197235, 0, 0, 0, 1),
            Qt.matrix4x4(-0.228539, -0.973406, -0.016197, 1.41912, 0.967722, -0.22533, -0.112881, 0.296719, 0.106229, -0.041471, 0.993477, 0.0309869, 0, 0, 0, 1),
            Qt.matrix4x4(-0.545886, -0.837769, 0.0126899, 1.28498, 0.837292, -0.5449, 0.0450559, 0.61753, -0.0308315, 0.035222, 0.998904, -0.0525147, 0, 0, 0, 1),
            Qt.matrix4x4(-0.436463, -0.899282, -0.0283436, 1.31956, 0.898301, -0.43733, 0.0424265, 0.190279, -0.0505485, -0.00694224, 0.998698, 0.00902915, 0, 0, 0, 1),
            Qt.matrix4x4(0.214882, 0.0996321, -0.971545, -0.224841, 0.805303, -0.580895, 0.118542, 0.128088, -0.552551, -0.807866, -0.205057, 1.29748, 0, 0, 0, 1),
            Qt.matrix4x4(-0.911357, -0.40391, -0.0792919, 1.07284, 0.152764, -0.510779, 0.846032, 0.433479, -0.382219, 0.75893, 0.527203, -0.628568, 0, 0, 0, 1),
            Qt.matrix4x4(-0.910877, -0.410869, 0.0386233, 1.07003, 0.228852, -0.425034, 0.875771, 0.240636, -0.343408, 0.806564, 0.48118, -0.703747, 0, 0, 0, 1),
            Qt.matrix4x4(-0.915606, -0.402046, 0.00519614, 1.06761, 0.32143, -0.724136, 0.610178, 0.49845, -0.241555, 0.560357, 0.792248, -0.541533, 0, 0, 0, 1),
            Qt.matrix4x4(-0.676881, 0.0493185, 0.734438, 0.386233, 0.664759, -0.387529, 0.638685, -0.0486791, 0.316113, 0.920545, 0.229526, -1.2612, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0559052, 0.0737927, 0.995706, -0.113636, 0.603827, -0.791726, 0.0925767, 0.423559, 0.795152, 0.606413, -0.000295496, -1.2485, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0299974, 0.0255314, 0.999224, -0.0817322, 0.72814, -0.684303, 0.0393432, 0.181392, 0.684772, 0.72876, 0.00193792, -1.29656, 0, 0, 0, 1),
            Qt.matrix4x4(0.00659696, 0.0338781, 0.999404, -0.118764, 0.589339, -0.80755, 0.0234831, 0.395205, 0.807859, 0.588837, -0.025292, -1.24181, 0, 0, 0, 1),
            Qt.matrix4x4(-0.369576, 0.0201167, 0.928983, 0.199048, 0.826574, -0.449607, 0.338571, -0.0799397, 0.424485, 0.893007, 0.149536, -1.30237, 0, 0, 0, 1),
            Qt.matrix4x4(-0.00149204, 0.0750538, 0.997178, -0.134579, 0.602791, -0.795586, 0.0607807, 0.431769, 0.797897, 0.601185, -0.0440538, -1.24403, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0232035, 0.0197901, 0.999535, -0.0592235, 0.720388, -0.692906, 0.0304411, 0.193194, 0.693182, 0.720765, 0.00182209, -1.29506, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0346721, 0.0381241, 0.998671, -0.0694649, 0.623567, -0.780081, 0.0514271, 0.329388, 0.781, 0.624527, 0.00327476, -1.26263, 0, 0, 0, 1),
            Qt.matrix4x4(0.119535, -0.0351894, 0.992206, -0.0798697, 0.85328, -0.507274, -0.120789, -0.0167166, 0.507568, 0.861074, -0.0306091, -1.31739, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0227768, 0.0188713, 0.999562, -0.0359474, 0.646935, -0.761993, 0.0291264, 0.366991, 0.762204, 0.64732, 0.00514798, -1.26863, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0391572, 0.0565006, 0.997634, -0.0637993, 0.731562, -0.678465, 0.067137, 0.171751, 0.680649, 0.732465, -0.0147659, -1.29755, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0192312, 0.0635523, 0.997793, -0.0866709, 0.625468, -0.77782, 0.0615949, 0.33089, 0.780012, 0.625277, -0.0247907, -1.26152, 0, 0, 0, 1),
            Qt.matrix4x4(0.603535, -0.100181, 0.791017, -0.334614, 0.644979, -0.521926, -0.558211, 0.160124, 0.468772, 0.847095, -0.250384, -1.26672, 0, 0, 0, 1),
            Qt.matrix4x4(0.00269811, -0.00251594, 0.999993, -0.0104808, 0.662273, -0.749258, -0.00367306, 0.345368, 0.749257, 0.662283, -0.000354494, -1.26894, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0178404, 0.0184224, 0.999671, -0.0176932, 0.743418, -0.668342, 0.0255826, 0.164698, 0.668589, 0.743635, -0.00177109, -1.29631, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0379369, 0.0555951, 0.997732, -0.0418587, 0.599239, -0.797747, 0.0672349, 0.39085, 0.79967, 0.600435, -0.00304999, -1.24384, 0, 0, 0, 1),
            Qt.matrix4x4(-0.22854, 0.973406, 0.016197, -1.41912, -0.967721, -0.22533, -0.112881, 0.296721, -0.106229, -0.0414711, 0.993477, 0.0309869, 0, 0, 0, 1),
            Qt.matrix4x4(-0.545886, 0.837769, -0.0126899, -1.28498, -0.837292, -0.5449, 0.0450559, 0.61753, 0.0308315, 0.035222, 0.998904, -0.0525147, 0, 0, 0, 1),
            Qt.matrix4x4(-0.436463, 0.899282, 0.0283436, -1.31956, -0.898301, -0.43733, 0.0424265, 0.190279, 0.0505485, -0.00694222, 0.998698, 0.00902913, 0, 0, 0, 1),
            Qt.matrix4x4(0.214882, -0.099632, 0.971545, 0.224841, -0.805303, -0.580895, 0.118542, 0.128088, 0.552551, -0.807866, -0.205057, 1.29748, 0, 0, 0, 1),
            Qt.matrix4x4(-0.911357, 0.40391, 0.0792919, -1.07284, -0.152765, -0.510779, 0.846032, 0.433479, 0.382219, 0.75893, 0.527203, -0.628568, 0, 0, 0, 1),
            Qt.matrix4x4(-0.910877, 0.410869, -0.0386233, -1.07003, -0.228853, -0.425034, 0.875771, 0.240635, 0.343408, 0.806564, 0.48118, -0.703747, 0, 0, 0, 1),
            Qt.matrix4x4(-0.915606, 0.402046, -0.0051961, -1.06761, -0.32143, -0.724135, 0.610177, 0.49845, 0.241555, 0.560357, 0.792248, -0.541533, 0, 0, 0, 1),
            Qt.matrix4x4(-0.676881, -0.0493184, -0.734439, -0.386233, -0.664759, -0.387529, 0.638685, -0.0486791, -0.316113, 0.920545, 0.229526, -1.2612, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0572975, -0.0727308, -0.995705, 0.11145, -0.603827, -0.791726, 0.0925766, 0.423558, -0.795053, 0.606542, 0.00144788, -1.24869, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0859952, 0.0342566, -0.995707, -0.0247606, -0.72814, -0.684303, 0.039343, 0.181392, -0.680012, 0.728402, 0.0837908, -1.2989, 0, 0, 0, 1),
            Qt.matrix4x4(0.00659709, -0.0338782, -0.999404, 0.118764, -0.589339, -0.80755, 0.023483, 0.395205, -0.807859, 0.588837, -0.0252923, -1.24181, 0, 0, 0, 1),
            Qt.matrix4x4(-0.369576, -0.0201166, -0.928983, -0.199049, -0.826575, -0.449607, 0.338571, -0.0799396, -0.424485, 0.893007, 0.149536, -1.30237, 0, 0, 0, 1),
            Qt.matrix4x4(-0.001492, -0.0750538, -0.997179, 0.134579, -0.602791, -0.795586, 0.0607808, 0.431769, -0.797897, 0.601185, -0.0440537, -1.24403, 0, 0, 0, 1),
            Qt.matrix4x4(0.0614502, -0.107485, -0.992306, 0.216616, -0.720389, -0.692907, 0.0304414, 0.193194, -0.690843, 0.71298, -0.120008, -1.27819, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0619076, -0.0163051, -0.997949, 0.0253574, -0.623568, -0.780081, 0.0514273, 0.329387, -0.779314, 0.625477, 0.0381262, -1.26428, 0, 0, 0, 1),
            Qt.matrix4x4(0.119535, 0.0351895, -0.992206, 0.0798695, -0.85328, -0.507274, -0.120789, -0.0167166, -0.507568, 0.861074, -0.030609, -1.31739, 0, 0, 0, 1),
            Qt.matrix4x4(0.0213182, -0.0562561, -0.998189, 0.109217, -0.646935, -0.761994, 0.0291264, 0.366991, -0.762247, 0.645147, -0.0526373, -1.26443, 0, 0, 0, 1),
            Qt.matrix4x4(-0.0225173, -0.0743779, -0.996976, 0.0954793, -0.731562, -0.678465, 0.067137, 0.171751, -0.681403, 0.730866, -0.0391336, -1.2956, 0, 0, 0, 1),
            Qt.matrix4x4(-0.00697758, -0.0733654, -0.997281, 0.106474, -0.625468, -0.77782, 0.061595, 0.33089, -0.780218, 0.624201, -0.0404594, -1.26, 0, 0, 0, 1),
            Qt.matrix4x4(0.603536, 0.100181, -0.791017, 0.334614, -0.644979, -0.521926, -0.558211, 0.160124, -0.468772, 0.847095, -0.250384, -1.26672, 0, 0, 0, 1),
            Qt.matrix4x4(0.0683758, -0.0555566, -0.996112, 0.121689, -0.662273, -0.749258, -0.00367319, 0.345368, -0.746136, 0.659954, -0.0880235, -1.26313, 0, 0, 0, 1),
            Qt.matrix4x4(0.00316907, -0.0417712, -0.999122, 0.0584021, -0.743418, -0.668343, 0.0255825, 0.164698, -0.66882, 0.742689, -0.0331703, -1.29511, 0, 0, 0, 1),
            Qt.matrix4x4(0.0249279, -0.102538, -0.994417, 0.13933, -0.59924, -0.797747, 0.0672348, 0.39085, -0.800181, 0.594222, -0.0813299, -1.23672, 0, 0, 0, 1),
            Qt.matrix4x4(1, -4.38041e-08, 3.84056e-07, 5.6338e-08, -3.36058e-08, 0.979933, 0.19936, -1.46394, -3.85083e-07, -0.19936, 0.979926, 0.275086, 0, 0, 0, 1),
            Qt.matrix4x4(1, -8.2043e-08, 5.87491e-07, 1.0841e-07, 2.13232e-08, 0.994722, 0.102676, -1.59573, -5.9281e-07, -0.102675, 0.994715, 0.11977, 0, 0, 0, 1)
        ]
    }

    // Nodes:
    Node {
        id: skeleton_human_male
        objectName: "skeleton_human_male"
        Model {
            id: human_male_base03
            objectName: "human_male_base03"
            source: "meshes/human_male_base03_mesh.mesh"
            skin: skin
            materials: [
                human_skin_001_material,
                cornea_001_material,
                human_eyes_001_material,
                fur_001_material,
                teeth_001_material
            ]
        }
        Node {
            id: root
            objectName: "root"
            position: Qt.vector3d(-6.33299e-09, 0.053951, -0.0178775)
            rotation: Qt.quaternion(0.643175, 0.765719, -8.09137e-07, -9.6874e-07)
            scale: Qt.vector3d(1, 1, 0.999993)
            Node {
                id: pelvis
                objectName: "pelvis"
                position: Qt.vector3d(-1.99264e-06, -0.0985552, -0.792141)
                rotation: Qt.quaternion(0.508447, -0.861093, 5.58938e-07, 1.23245e-06)
                scale: Qt.vector3d(1, 1, 1)
                Node {
                    id: thigh_R
                    objectName: "thigh_R"
                    position: Qt.vector3d(-0.115628, 0.0797588, 0.0157119)
                    rotation: Qt.quaternion(0.0444167, 0.00615934, -0.161981, 0.985775)
                    scale: Qt.vector3d(1, 1, 1)
                    Node {
                        id: calf_R
                        objectName: "calf_R"
                        position: Qt.vector3d(1.13941e-08, 0.435987, -8.14907e-10)
                        rotation: Qt.quaternion(0.999742, -0.0102889, 0.0197224, -0.00460058)
                        scale: Qt.vector3d(1, 1, 1)
                        Node {
                            id: foot_R
                            objectName: "foot_R"
                            position: Qt.vector3d(1.52795e-08, 0.39553, -6.98492e-10)
                            rotation: Qt.quaternion(0.85899, 0.511005, 0.0189186, 0.025543)
                            scale: Qt.vector3d(1, 1, 1)
                            Node {
                                id: toes_R
                                objectName: "toes_R"
                                position: Qt.vector3d(-1.16415e-10, 0.169244, 2.09548e-09)
                                rotation: Qt.quaternion(0.00200512, 0.0438584, 0.978845, 0.199839)
                                scale: Qt.vector3d(1, 1, 1)
                            }
                        }
                    }
                }
                Node {
                    id: thigh_L
                    objectName: "thigh_L"
                    position: Qt.vector3d(0.115629, 0.0797588, 0.0157118)
                    rotation: Qt.quaternion(-0.0444167, -0.006159, -0.161981, 0.985775)
                    scale: Qt.vector3d(1, 1, 1)
                    Node {
                        id: calf_L
                        objectName: "calf_L"
                        position: Qt.vector3d(-3.00788e-08, 0.435987, -3.20142e-10)
                        rotation: Qt.quaternion(0.999742, -0.0102889, -0.0197224, 0.00460059)
                        scale: Qt.vector3d(1, 1, 1)
                        Node {
                            id: foot_L
                            objectName: "foot_L"
                            position: Qt.vector3d(-1.23982e-08, 0.39553, 2.32831e-10)
                            rotation: Qt.quaternion(0.85899, 0.511006, -0.0189186, -0.025543)
                            scale: Qt.vector3d(1, 1, 1)
                            Node {
                                id: toes_L
                                objectName: "toes_L"
                                position: Qt.vector3d(-1.72295e-08, 0.169244, -6.98492e-09)
                                rotation: Qt.quaternion(0.978591, 0.198883, 0.0223843, 0.0480096)
                                scale: Qt.vector3d(1, 1, 1)
                            }
                        }
                    }
                }
                Node {
                    id: spine01
                    objectName: "spine01"
                    position: Qt.vector3d(-5.44009e-15, 0.176569, 2.98023e-08)
                    rotation: Qt.quaternion(0.971081, 0.238749, -6.34044e-08, -1.26149e-07)
                    scale: Qt.vector3d(1, 1, 1)
                    Node {
                        id: spine02
                        objectName: "spine02"
                        position: Qt.vector3d(1.28786e-14, 0.114618, -9.31323e-09)
                        rotation: Qt.quaternion(0.992266, -0.12413, 1.14822e-07, 1.16064e-07)
                        Node {
                            id: spine03
                            objectName: "spine03"
                            position: Qt.vector3d(-1.68754e-14, 0.114071, 3.72529e-09)
                            rotation: Qt.quaternion(0.998996, 0.0447893, -7.88404e-08, -6.52564e-08)
                            scale: Qt.vector3d(1, 1, 1)
                            Node {
                                id: clavicle_L
                                objectName: "clavicle_L"
                                position: Qt.vector3d(0.0338907, 0.204028, 0.0565092)
                                rotation: Qt.quaternion(0.620511, -0.0264015, 0.0523256, -0.782005)
                                scale: Qt.vector3d(1, 1, 1)
                                Node {
                                    id: upperarm_L
                                    objectName: "upperarm_L"
                                    position: Qt.vector3d(1.81026e-08, 0.153854, -3.72529e-09)
                                    rotation: Qt.quaternion(0.981789, 0.0781315, -0.00834667, -0.172961)
                                    scale: Qt.vector3d(1, 1, 1)
                                    Node {
                                        id: lowerarm_L
                                        objectName: "lowerarm_L"
                                        position: Qt.vector3d(9.38016e-08, 0.265962, 0)
                                        rotation: Qt.quaternion(0.997816, -0.00179785, 0.0232039, 0.061821)
                                        scale: Qt.vector3d(1, 1, 1)
                                        Node {
                                            id: hand_L
                                            objectName: "hand_L"
                                            position: Qt.vector3d(-1.82248e-07, 0.285676, 9.31323e-10)
                                            rotation: Qt.quaternion(0.643307, 0.0907315, 0.759864, -0.0230449)
                                            scale: Qt.vector3d(1, 1, 1)
                                            Node {
                                                id: thumb01_L
                                                objectName: "thumb01_L"
                                                position: Qt.vector3d(-0.0161352, 0.0171172, 0.00206089)
                                                rotation: Qt.quaternion(-0.461238, -0.455784, 0.739776, -0.179587)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: thumb02_L
                                                    objectName: "thumb02_L"
                                                    position: Qt.vector3d(-8.14907e-08, 0.0435519, 5.96046e-08)
                                                    rotation: Qt.quaternion(0.997881, 0.0273098, -0.0269727, 0.0525417)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: thumb03_L
                                                        objectName: "thumb03_L"
                                                        position: Qt.vector3d(5.58794e-09, 0.037428, -1.11759e-08)
                                                        rotation: Qt.quaternion(0.978676, -0.204667, 0.00708658, -0.0159428)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                    }
                                                }
                                            }
                                            Node {
                                                id: index00_L
                                                objectName: "index00_L"
                                                position: Qt.vector3d(3.72529e-09, 0.0377327, -3.58559e-08)
                                                rotation: Qt.quaternion(-0.0645721, -0.262284, 0.955985, -0.114586)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: index01_L
                                                    objectName: "index01_L"
                                                    position: Qt.vector3d(-1.11759e-08, 0.0574048, 3.1665e-08)
                                                    rotation: Qt.quaternion(0.915098, -0.22131, -0.215094, 0.259523)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: index02_L
                                                        objectName: "index02_L"
                                                        position: Qt.vector3d(0, 0.0375615, 2.99406e-09)
                                                        rotation: Qt.quaternion(0.996243, 0.0821369, 0.00654685, 0.0266518)
                                                        Node {
                                                            id: index03_L
                                                            objectName: "index03_L"
                                                            position: Qt.vector3d(9.31323e-09, 0.0244, -1.12341e-07)
                                                            rotation: Qt.quaternion(0.995516, -0.0927144, -0.0164777, 0.00898325)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: middle00_L
                                                objectName: "middle00_L"
                                                position: Qt.vector3d(3.72529e-09, 0.0377327, -3.58559e-08)
                                                rotation: Qt.quaternion(0.00943887, -0.0996558, 0.991658, -0.0812037)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: middle01_L
                                                    objectName: "middle01_L"
                                                    position: Qt.vector3d(-9.31323e-09, 0.0479887, 2.14204e-08)
                                                    rotation: Qt.quaternion(0.958373, -0.213853, -0.14066, 0.126505)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: middle02_L
                                                        objectName: "middle02_L"
                                                        position: Qt.vector3d(-2.56114e-09, 0.0415146, -8.61473e-09)
                                                        rotation: Qt.quaternion(0.996482, 0.0783667, 0.0264751, 0.0134838)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                        Node {
                                                            id: middle03_L
                                                            objectName: "middle03_L"
                                                            position: Qt.vector3d(5.58794e-09, 0.0293453, 1.3104e-08)
                                                            rotation: Qt.quaternion(0.997819, -0.0651167, -0.00194248, -0.0106456)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: ring00_L
                                                objectName: "ring00_L"
                                                position: Qt.vector3d(3.72529e-09, 0.0377327, -3.58559e-08)
                                                rotation: Qt.quaternion(0.118219, 0.122995, 0.984771, -0.0335047)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: ring01_L
                                                    objectName: "ring01_L"
                                                    position: Qt.vector3d(-1.49012e-08, 0.0424741, 1.14087e-07)
                                                    rotation: Qt.quaternion(0.9833, -0.16527, 0.0252585, -0.0718978)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: ring02_L
                                                        objectName: "ring02_L"
                                                        position: Qt.vector3d(3.72529e-09, 0.0406718, -1.53144e-07)
                                                        rotation: Qt.quaternion(0.998025, 0.0593643, -0.00708991, -0.0192803)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                        Node {
                                                            id: ring03_L
                                                            objectName: "ring03_L"
                                                            position: Qt.vector3d(-5.58794e-09, 0.0278034, 1.29919e-07)
                                                            rotation: Qt.quaternion(0.997305, -0.0726067, -0.00969443, 0.00420923)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: pinky00_L
                                                objectName: "pinky00_L"
                                                position: Qt.vector3d(3.72529e-09, 0.0377327, -3.58559e-08)
                                                rotation: Qt.quaternion(0.232165, 0.348853, 0.907913, 0.00976882)
                                                Node {
                                                    id: pinky01_L
                                                    objectName: "pinky01_L"
                                                    position: Qt.vector3d(-7.45058e-09, 0.0458687, -1.53668e-07)
                                                    rotation: Qt.quaternion(0.938813, -0.12279, 0.169583, -0.273488)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: pinky02_L
                                                        objectName: "pinky02_L"
                                                        position: Qt.vector3d(-9.31323e-10, 0.0330428, -2.81607e-08)
                                                        rotation: Qt.quaternion(0.99825, 0.0572872, -7.95022e-05, -0.0146656)
                                                        Node {
                                                            id: pinky03_L
                                                            objectName: "pinky03_L"
                                                            position: Qt.vector3d(-1.86265e-09, 0.0200649, 3.83407e-08)
                                                            rotation: Qt.quaternion(0.995066, -0.0969328, -0.0051415, -0.0205164)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            Node {
                                id: clavicle_R
                                objectName: "clavicle_R"
                                position: Qt.vector3d(-0.0338906, 0.204028, 0.0565093)
                                rotation: Qt.quaternion(0.62051, -0.0264012, -0.0523253, 0.782005)
                                scale: Qt.vector3d(1, 1, 1)
                                Node {
                                    id: upperarm_R
                                    objectName: "upperarm_R"
                                    position: Qt.vector3d(-7.2032e-09, 0.153854, 0)
                                    rotation: Qt.quaternion(0.981789, 0.0781315, 0.00834666, 0.172961)
                                    scale: Qt.vector3d(1, 1, 1)
                                    Node {
                                        id: lowerarm_R
                                        objectName: "lowerarm_R"
                                        position: Qt.vector3d(-1.38069e-07, 0.265962, 3.72529e-09)
                                        rotation: Qt.quaternion(0.997816, -0.00179785, -0.0232039, -0.061821)
                                        scale: Qt.vector3d(1, 1, 1)
                                        Node {
                                            id: hand_R
                                            objectName: "hand_R"
                                            position: Qt.vector3d(3.34112e-08, 0.285676, 5.58794e-09)
                                            rotation: Qt.quaternion(0.643307, 0.0907315, -0.759864, 0.0230449)
                                            scale: Qt.vector3d(1, 1, 1)
                                            Node {
                                                id: thumb01_R
                                                objectName: "thumb01_R"
                                                position: Qt.vector3d(0.0161352, 0.0171171, 0.00206108)
                                                rotation: Qt.quaternion(0.461238, 0.455784, 0.739776, -0.179587)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: thumb02_R
                                                    objectName: "thumb02_R"
                                                    position: Qt.vector3d(1.86265e-08, 0.0435519, 3.72529e-08)
                                                    rotation: Qt.quaternion(0.997881, 0.0273098, 0.0269726, -0.0525418)
                                                    Node {
                                                        id: thumb03_R
                                                        objectName: "thumb03_R"
                                                        position: Qt.vector3d(5.26197e-08, 0.037428, -8.19564e-08)
                                                        rotation: Qt.quaternion(0.978676, -0.204667, -0.00708656, 0.0159428)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                    }
                                                }
                                            }
                                            Node {
                                                id: index00_R
                                                objectName: "index00_R"
                                                position: Qt.vector3d(1.49012e-08, 0.0377326, 1.45752e-07)
                                                rotation: Qt.quaternion(0.0645722, 0.262284, 0.955985, -0.114586)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: index01_R
                                                    objectName: "index01_R"
                                                    position: Qt.vector3d(-2.98023e-08, 0.0574048, -9.31323e-08)
                                                    rotation: Qt.quaternion(0.915286, -0.221537, 0.214293, -0.259329)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: index02_R
                                                        objectName: "index02_R"
                                                        position: Qt.vector3d(1.11759e-08, 0.0375615, -3.02607e-08)
                                                        rotation: Qt.quaternion(0.995178, 0.0809489, -0.0465121, -0.0300676)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                        Node {
                                                            id: index03_R
                                                            objectName: "index03_R"
                                                            position: Qt.vector3d(3.72529e-09, 0.0244, -4.51691e-08)
                                                            rotation: Qt.quaternion(0.994003, -0.0930047, 0.0572761, -0.00517478)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: middle00_R
                                                objectName: "middle00_R"
                                                position: Qt.vector3d(1.49012e-08, 0.0377326, 1.45752e-07)
                                                rotation: Qt.quaternion(-0.00943875, 0.0996558, 0.991658, -0.0812037)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: middle01_R
                                                    objectName: "middle01_R"
                                                    position: Qt.vector3d(2.04891e-08, 0.0479888, -3.25963e-08)
                                                    rotation: Qt.quaternion(0.958373, -0.213853, 0.14066, -0.126505)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: middle02_R
                                                        objectName: "middle02_R"
                                                        position: Qt.vector3d(9.66247e-09, 0.0415147, 1.15018e-07)
                                                        rotation: Qt.quaternion(0.996239, 0.0790437, 0.0344102, -0.00867425)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                        Node {
                                                            id: middle03_R
                                                            objectName: "middle03_R"
                                                            position: Qt.vector3d(-3.72529e-09, 0.0293453, 6.98492e-08)
                                                            rotation: Qt.quaternion(0.994895, -0.065519, -0.0763538, 0.00779494)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: ring00_R
                                                objectName: "ring00_R"
                                                position: Qt.vector3d(1.49012e-08, 0.0377326, 1.45752e-07)
                                                rotation: Qt.quaternion(-0.118219, -0.122995, 0.984771, -0.0335046)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: ring01_R
                                                    objectName: "ring01_R"
                                                    position: Qt.vector3d(1.11759e-08, 0.0424742, 2.9162e-08)
                                                    rotation: Qt.quaternion(0.983619, -0.16728, 0.00318235, 0.0670893)
                                                    Node {
                                                        id: ring02_R
                                                        objectName: "ring02_R"
                                                        position: Qt.vector3d(0, 0.0406717, -7.63685e-08)
                                                        rotation: Qt.quaternion(0.998004, 0.0585211, -0.00957822, 0.0217051)
                                                        Node {
                                                            id: ring03_R
                                                            objectName: "ring03_R"
                                                            position: Qt.vector3d(-3.72529e-09, 0.0278035, -8.35862e-08)
                                                            rotation: Qt.quaternion(0.997337, -0.0725076, 0.00534347, -0.00566547)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                            Node {
                                                id: pinky00_R
                                                objectName: "pinky00_R"
                                                position: Qt.vector3d(1.49012e-08, 0.0377326, 1.45752e-07)
                                                rotation: Qt.quaternion(-0.232165, -0.348853, 0.907913, 0.00976877)
                                                scale: Qt.vector3d(1, 1, 1)
                                                Node {
                                                    id: pinky01_R
                                                    objectName: "pinky01_R"
                                                    position: Qt.vector3d(-1.95578e-08, 0.0458687, -9.42964e-08)
                                                    rotation: Qt.quaternion(0.945349, -0.134671, -0.128226, 0.267837)
                                                    scale: Qt.vector3d(1, 1, 1)
                                                    Node {
                                                        id: pinky02_R
                                                        objectName: "pinky02_R"
                                                        position: Qt.vector3d(9.31323e-09, 0.0330428, -9.65083e-08)
                                                        rotation: Qt.quaternion(0.997856, 0.056312, -0.0280515, 0.0180518)
                                                        scale: Qt.vector3d(1, 1, 1)
                                                        Node {
                                                            id: pinky03_R
                                                            objectName: "pinky03_R"
                                                            position: Qt.vector3d(-2.56114e-09, 0.0200649, -3.40806e-08)
                                                            rotation: Qt.quaternion(0.994669, -0.0979137, 0.0285878, 0.0151585)
                                                            scale: Qt.vector3d(1, 1, 1)
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            Node {
                                id: neck
                                objectName: "neck"
                                position: Qt.vector3d(2.43171e-08, 0.243939, 0.0534074)
                                rotation: Qt.quaternion(0.994578, 0.10399, 5.27857e-09, -1.81353e-08)
                                Node {
                                    id: head
                                    objectName: "head"
                                    position: Qt.vector3d(1.11022e-15, 0.112452, -7.45058e-09)
                                    rotation: Qt.quaternion(0.998803, -0.0489043, -1.03439e-07, -3.52007e-09)
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Animations:

    // An exported mapping of Timelines (--manualAnimations)
    property var timelineMap: {
    }
    // A simple list of Timelines (--manualAnimations)
    property var timelineList: [
    ]
}
