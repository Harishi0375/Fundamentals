<?php
include './access_log.php';
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>About Us - Founders</title>
    <link rel="stylesheet" href="About.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta2/css/all.min.css" integrity="sha512-YWzhKL2whUzgiheMoBFwW8CKV4qpHQAEuvilg9FAn5VJUDwKZZxkJNuGM4XkWuk94WCrrwslk8yWNGmY1EduTA==" crossorigin="anonymous" referrerpolicy="no-referrer">
</head>

<body>

    <!-- Navbar -->
    <div id="navbar">
        <div class="logo">
            <a href="../index.php">
                <img src="../content/symbol-transp.png" alt="FindYourGspot Logo" class="logo-img">
            </a>
        </div>
        <div>
            <a href="../../index.php">Home</a>
            <a href="About.php">About</a>
            <a href="GDPR.php">GDPR</a>
            <a href="Login_page.php">Log In</a>
            <a href="Register_page.php">Register</a>
        </div>
    </div>

    <!-- Founders Section -->
    <h1 class="gradient-title">Founders</h1>
    <div class="founders">
        <div class="founder">
            <img src="content/Mateo.png" alt="Mateo Pico">
            <p class="founder-name">Mateo Pico</p>
        </div>
        <div class="founder">
            <img src="content/Nik.jpeg" alt="Nik Tsonev">
            <p class="founder-name">Nik Tsonev</p>
        </div>
        <div class="founder">
            <img src="content/Harishi.jpg" alt="Harishi Velevan">
            <p class="founder-name">Harishi Velevan</p>
        </div>
    </div>

    <!-- Customer Reviews Section -->
    <h2 class="gradient-title">Customer Reviews</h2>
    <div class="customer-reviews">
        <div class="review">
            <img src="content/Tim-Customer.jpg" alt="Customer 1" class="customer-photo">
            <div class="review-text">
                <p>"Thanks to this page I have finally found my G Spot. The process was extremly easy and there was plenty of customer support."</p>
                <p>- Tim Bense</p>
            </div>
        </div>
        <div class="review flip">
            <img src="content/Mike-Customer.jpg" alt="Customer 2" class="customer-photo">
            <div class="review-text">
                <p>"This service has been a game-changer for finding my perfect home! I highly recomend people to use this page."</p>
                <p>- Mike Teshome</p>
            </div>
        </div>
        <div class="review">
            <img src="content/Vitor-Customer.jpg" alt="Customer 3" class="customer-photo">
            <div class="review-text">
                <p>"Thanks to findyourGspot I now feel confident on where I will live for the next couple of years"</p>
                <p>- Vitor Furiato</p>
            </div>
        </div>
    </div>

    <!-- Footer -->
    <footer>
        <div>&copy; 2024 FindYourGspot</div>
        <div id="social-media">
            <a href="#" target="_blank"><i class="fab fa-facebook"></i></a>
            <a href="#" target="_blank"><i class="fab fa-instagram"></i></a>
            <a href="#" target="_blank"><i class="fab fa-twitter"></i></a>
        </div>
    </footer>

</body>

</html>