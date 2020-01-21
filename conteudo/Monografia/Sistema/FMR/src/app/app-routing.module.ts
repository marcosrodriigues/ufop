import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { IndexComponent } from './page/index/index.component';
import { SobreComponent } from './page/sobre/sobre.component';
import { LoginComponent } from './page/login/login.component';
import { SearchComponent } from './page/search/search.component';
import { RepublicDetailComponent } from './page/republic-detail/republic-detail.component';
import { ProfileComponent } from './page/profile/profile.component';
import { MyRepublicComponent } from './page/my-republic/my-republic.component';
import { InventoryComponent } from './page/inventory/inventory.component';
import { ComoUsarComponent } from './page/como-usar/como-usar.component';
import { AdminIndexComponent } from './admin/page/admin-index/admin-index.component';


const routes: Routes = [
  { path: '', component: IndexComponent, pathMatch: 'full' },
  { path: 'sobre', component: SobreComponent, pathMatch: 'full' },
  { path: 'login', component: LoginComponent, pathMatch: 'full' },
  { path: 'search/:cidade/:carater', component: SearchComponent, pathMatch: 'full' },
  { path: 'republica/:id', component: RepublicDetailComponent, pathMatch: 'full'},
  { path: 'profile', component: ProfileComponent, pathMatch: 'full'},
  { path: 'profile/republica', component: MyRepublicComponent, pathMatch: 'full' },
  { path: 'inventario', component: InventoryComponent, pathMatch: 'full' },
  { path : 'como-usar', component: ComoUsarComponent, pathMatch: 'full' },
  { path : 'admin/index', component: AdminIndexComponent, pathMatch: 'full'},
  { path: '**', redirectTo:'', pathMatch:'full' },

];

@NgModule({
  imports: [RouterModule.forRoot(routes, {
    onSameUrlNavigation: 'reload'
  })],
  exports: [RouterModule]
})
export class AppRoutingModule { }
