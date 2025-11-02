<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Documentation du Projet Minishell</title>
    <!-- Chargement de Tailwind CSS pour un rendu moderne -->
    <script src="https://cdn.tailwindcss.com"></script>
    <style>
        /* Configuration de la police Inter */
        html { font-family: 'Inter', sans-serif; }
        /* Style des blocs de code */
        pre {
            background-color: #1e1e1e;
            color: #d4d4d4;
            padding: 1rem;
            border-radius: 0.5rem;
            overflow-x: auto;
            margin-top: 0.5rem;
            margin-bottom: 1rem;
        }
        code {
            font-family: 'Fira Code', 'Menlo', 'Monaco', 'Consolas', 'Courier New', monospace;
        }
        /* Style pour les images de documentation */
        .doc-image {
            margin-top: 1rem;
            margin-bottom: 2rem;
            border-radius: 0.5rem;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -2px rgba(0, 0, 0, 0.1);
        }
    </style>
</head>
<body class="bg-gray-50 p-4 sm:p-8">

<div class="max-w-4xl mx-auto bg-white p-6 sm:p-10 rounded-xl shadow-2xl">

    <!-- H1: Documentation du Projet Minishell -->
    <h1 class="text-3xl sm:text-4xl font-extrabold text-blue-800 mb-6 border-b pb-3">
        Documentation du Projet Minishell
    </h1>
    <p class="mb-6 leading-relaxed text-gray-700">
        Notre Minishell est un shell que nous avons développé en langage C dans le cadre du projet final du cours "Systèmes d’exploitation" de la seconde année de licence informatique à distance de l’Université Paris 8, sous la direction du professeur Philippe KISLIN.
    </p>

    <!-- H2: COMPILATION DU SHELL -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        ⚙️ COMPILATION DU SHELL
    </h2>
    <p class="mb-4 text-gray-700">Pour compiler le minishell, utilisez la commande suivante :</p>
    <pre><code class="language-bash">$ make</code></pre>
    <!-- [Image Placeholder: Compilation] -->
    <img src="https://placehold.co/800x200/4F46E5/FFFFFF?text=Compilation+avec+Make" alt="Capture d'écran de la compilation avec make" class="doc-image w-full h-auto">


    <!-- H2: LANCEMENT DU SHELL -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        🚀 LANCEMENT DU SHELL
    </h2>
    <p class="mb-4 text-gray-700">Pour exécuter le minishell :</p>
    <pre><code class="language-bash">$ ./monshell</code></pre>
    <!-- [Image Placeholder: Lancement] -->
    <img src="https://placehold.co/800x200/4F46E5/FFFFFF?text=Lancement+du+Minishell" alt="Capture d'écran de l'exécution du minishell" class="doc-image w-full h-auto">
    
    <!-- H2: COMMANDES INTERNES -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        🛠️ COMMANDES INTERNES (Built-in)
    </h2>
    <p class="mb-4 text-gray-700">Notre shell supporte plusieurs commandes intégrées (built-in) essentielles pour la gestion des processus et de l'environnement.</p>

    <!-- monhelp -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        <code>monhelp</code>
    </h3>
    <p class="text-gray-700">Affiche le message d'aide du shell (cette documentation).</p>
    <pre><code class="language-bash">$ monhelp</code></pre>
    <img src="https://placehold.co/800x300/F59E0B/FFFFFF?text=monhelp+output" alt="Capture d'écran de monhelp" class="doc-image w-full h-auto">

    <!-- moncd -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        <code>moncd &lt;chemin&gt;</code>
    </h3>
    <p class="text-gray-700">Change le répertoire courant de l'utilisateur.</p>
    <pre><code class="language-bash"># Afficher le répertoire actuel
$ pwd
# Changer de répertoire
$ moncd ..
# Vérifier le nouveau répertoire
$ pwd</code></pre>
    <img src="https://placehold.co/800x300/F59E0B/FFFFFF?text=moncd+execution" alt="Capture d'écran de moncd" class="doc-image w-full h-auto">
    
    <!-- monexit -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        <code>monexit</code>
    </h3>
    <p class="text-gray-700">Quitte le shell proprement, en terminant tous les processus en arrière-plan.</p>
    <pre><code class="language-bash">$ monexit</code></pre>
    <img src="https://placehold.co/800x150/F59E0B/FFFFFF?text=monexit+command" alt="Capture d'écran de monexit" class="doc-image w-full h-auto">
    
    <!-- monsleep -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        <code>monsleep &lt;secondes&gt;</code>
    </h3>
    <p class="text-gray-700">Met le shell en pause pendant le nombre de secondes spécifié. Cette commande est robuste et gère les erreurs de saisie.</p>
    <pre><code class="language-bash"># Exemple de tentatives invalides
$ monsleep
$ monsleep 1 1 1
$ monsleep 1m 10s 5s</code></pre>
    <img src="https://placehold.co/800x300/F59E0B/FFFFFF?text=monsleep+robustesse" alt="Capture d'écran de monsleep" class="doc-image w-full h-auto">

    <!-- H2: GESTION DES FLUX -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        🔄 GESTION DES FLUX (PIPES et REDIRECTIONS)
    </h2>
    <p class="mb-4 text-gray-700">Notre shell gère le chaînage de processus et la manipulation des flux d'entrée/sortie standard.</p>

    <!-- PIPE -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        PIPE (<code>|</code>)
    </h3>
    <p class="text-gray-700">Permet de chaîner des commandes. La sortie standard (STDOUT) de la première commande devient l'entrée standard (STDIN) de la seconde.</p>
    <pre><code class="language-bash">$ ls | grep a</code></pre>
    <img src="https://placehold.co/800x150/10B981/FFFFFF?text=PIPE+example" alt="Capture d'écran de la commande PIPE" class="doc-image w-full h-auto">


    <!-- REDIRECTIONS -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        REDIRECTIONS
    </h3>
    <ol class="list-decimal ml-6 space-y-4 text-gray-700">
        <li>
            <p class="font-medium">Redirection de la sortie standard (STDOUT) vers un fichier en écrasant ses données (<code>&gt;</code>):</p>
            <pre><code class="language-bash">$ ls | grep a > sortie.txt</code></pre>
        </li>
        <li>
            <p class="font-medium">Redirection de l’entrée standard (STDIN) depuis un fichier (<code>&lt;</code>):</p>
            <pre><code class="language-bash">$ cat < erreurs.txt</code></pre>
        </li>
        <li>
            <p class="font-medium">Redirection de l’erreur standard (STDERR) vers un fichier en écrasant ses données (<code>2&gt;</code>):</p>
            <pre><code class="language-bash">$ copier -coller 2> erreurs.txt</code></pre>
            <p class="text-sm italic text-gray-500">(Ici, `copier -coller` est supposé être une commande qui génère une erreur, enregistrée dans `erreurs.txt`)</p>
        </li>
        <li>
            <p class="font-medium">Redirection de l’erreur standard vers la fin du fichier (<code>2&gt;&gt;</code>):</p>
            <pre><code class="language-bash">$ ajouter -RAM 2>> erreurs.txt</code></pre>
        </li>
    </ol>
    <img src="https://placehold.co/800x400/10B981/FFFFFF?text=REDIRECTIONS+exemples" alt="Capture d'écran des redirections" class="doc-image w-full h-auto">


    <!-- H2: COMMANDES D'ARRIÈRE-PLAN -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        🏃 COMMANDES D'ARRIÈRE-PLAN
    </h2>
    <p class="mb-4 text-gray-700">Le shell permet de lancer des processus en arrière-plan en utilisant l'opérateur <code>&amp;</code>.</p>
    <pre><code class="language-bash">$ gedit &amp;</code></pre>
    <img src="https://placehold.co/800x150/EF4444/FFFFFF?text=Commandes+Arrière-plan" alt="Capture d'écran d'une commande d'arrière-plan" class="doc-image w-full h-auto">


    <!-- H2: ERREURS CONSTATÉES -->
    <h2 class="text-2xl sm:text-3xl font-bold text-gray-700 mt-8 mb-4 border-l-4 border-blue-500 pl-3">
        🐞 TESTS DE ROBUSTESSE
    </h2>

    <!-- Test de commande inexistante -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        Test de commande inexistante avec pipe et double redirection
    </h3>
    <p class="text-gray-700">Lorsque la première commande du pipe (<code>copier</code>) n'existe pas, l'erreur est correctement capturée et redirigée vers <code>erreurs.txt</code>.</p>
    <pre><code class="language-bash">$ copier | grep a > sortie.txt 2> erreurs.txt</code></pre>
    <img src="https://placehold.co/800x200/EF4444/FFFFFF?text=Test+Commande+Inexistante" alt="Capture d'écran du test de commande inexistante" class="doc-image w-full h-auto">


    <!-- Test de téléchargement -->
    <h3 class="text-xl font-semibold text-gray-600 mt-6 mb-2 border-b border-gray-200 pb-1">
        Test de téléchargement en arrière-plan avec double redirection
    </h3>
    <p class="text-gray-700">Démonstration de la robustesse en gérant une commande externe (<code>wget</code>) en arrière-plan (<code>&amp;</code>), tout en redirigeant sa sortie standard (<code>&gt;&gt;</code>) et ses erreurs standard (<code>2&gt;</code>) vers des fichiers séparés.</p>
    <pre><code class="language-bash">$ wget -O nginx.tar.gz https://nginx.org/download/nginx-1.18.0.tar.gz >> sortie.txt 2> erreurs.txt &amp;</code></pre>
    <img src="https://placehold.co/800x300/EF4444/FFFFFF?text=Test+WGET+en+Arrière-plan" alt="Capture d'écran du test de téléchargement" class="doc-image w-full h-auto">

</div>

</body>
</html>

