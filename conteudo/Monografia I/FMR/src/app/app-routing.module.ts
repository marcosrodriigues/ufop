import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { IndexComponent } from './page/index/index.component';
import { SobreComponent } from './page/sobre/sobre.component';
import { LoginComponent } from './page/login/login.component';


const routes: Routes = [
  { path: '', component: IndexComponent },
  { path: 'sobre', component: SobreComponent},
  { path: 'login', component: LoginComponent}

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
